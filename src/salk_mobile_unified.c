#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void cazar_intrusos() {
    // Lista de Firmas Agresiva para Android
    const char* firmas[] = {
        "hacker", "anydesk", "teamviewer", "scrcpy", 
        "metasploit", "spy", "rat", "trojan", "keylogger",
        "msfvenom", "meterpreter"
    };
    DIR* dir = opendir("/proc");
    struct dirent* ent;
    if (!dir) return;
    while ((ent = readdir(dir))) {
        if (ent->d_type == DT_DIR && atoi(ent->d_name) > 0) {
            char path[256];
            char buf[1024];
            sprintf(path, "/proc/%s/cmdline", ent->d_name);
            FILE* f = fopen(path, "r");
            if (f) {
                size_t len = fread(buf, 1, sizeof(buf)-1, f);
                buf[len] = 0;
                for(int i=0; i<11; i++) {
                    if (strstr(buf, firmas[i])) {
                        printf("[!] INTRUSO NEUTRALIZADO: %s (PID: %s)\n", buf, ent->d_name);
                        char kill_cmd[64];
                        sprintf(kill_cmd, "kill -9 %s", ent->d_name);
                        system(kill_cmd);
                    }
                }
                fclose(f);
            }
        }
    }
    closedir(dir);
}

void leer_propiedad(const char* prop, char* buffer, size_t size) {
    char command[128];
    sprintf(command, "getprop %s", prop);
    FILE *fp = popen(command, "r");
    if (fp) {
        if (fgets(buffer, size, fp)) buffer[strcspn(buffer, "\n")] = 0;
        pclose(fp);
    }
}

int main(int argc, char* argv[]) {
    char serial[128], model[128];
    leer_propiedad("ro.serialno", serial, sizeof(serial));
    leer_propiedad("ro.product.model", model, sizeof(model));

    printf("\n>>> ALBEDRIO SECURITY MOBILE v1.1 <<<\n");
    printf("[+] Resonancia: %s | Hardware: %s\n", serial, model);
    
    if (argc > 1 && strcmp(argv[1], "--attack") == 0) {
        printf("[+] Petaboom Mobile: Lanzando contraataque de saturacion...\n");
        for(int i=0; i<5; i++) { printf("  [Materia Oscura] Rafaga %d enviada.\n", i+1); usleep(100000); }
    } else {
        printf("[+] Iniciando Caceria Sentinela (Radar Activo)...\n");
        while(1) {
            cazar_intrusos();
            usleep(500000);
        }
    }
    return 0;
}
