#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void neutralizar(const char* pid, const char* razon) {
    printf("[!] INTRUSO NEUTRALIZADO: %s (PID: %s)\n", razon, pid);
    char kill_cmd[64];
    sprintf(kill_cmd, "kill -9 %s", pid);
    system(kill_cmd);
}

int main() {
    printf("[SALK-SENTINEL-MOBILE v1.5] Modo Cacería Activo.\n");
    
    const char* firmas[] = {"hacker", "anydesk", "teamviewer", "metasploit", "spy", "rat"};
    
    while (1) {
        DIR* dir = opendir("/proc");
        struct dirent* ent;
        if (!dir) continue;
        
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR && atoi(ent->d_name) > 0) {
                char path[256];
                char buf[1024];
                
                // Escaneo de CMDLINE (Comandos)
                sprintf(path, "/proc/%s/cmdline", ent->d_name);
                FILE* f = fopen(path, "r");
                if (f) {
                    size_t len = fread(buf, 1, sizeof(buf)-1, f);
                    buf[len] = 0;
                    for(int i=0; i<6; i++) {
                        if (strstr(buf, firmas[i])) {
                            neutralizar(ent->d_name, buf);
                            break;
                        }
                    }
                    fclose(f);
                }
            }
        }
        closedir(dir);
        usleep(500000); // Escaneo rápido cada 0.5 segundos
    }
    return 0;
}
