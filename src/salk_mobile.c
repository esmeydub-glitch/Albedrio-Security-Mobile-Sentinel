#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * SALK MOBILE v1.1 - Inyección Universal
 * Sin dependencias de SDK.
 */

void leer_propiedad(const char* prop, char* buffer, size_t size) {
    char command[128];
    sprintf(command, "getprop %s", prop);
    FILE *fp = popen(command, "r");
    if (fp != NULL) {
        if (fgets(buffer, size, fp) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0; // Limpiar salto de línea
        }
        pclose(fp);
    }
}

int main() {
    char serial[128] = "DESCONOCIDO";
    char model[128] = "GENERIC-MOBILE";
    
    // Obtenemos identidad mediante inyección de comandos nativos
    leer_propiedad("ro.serialno", serial, sizeof(serial));
    leer_propiedad("ro.product.model", model, sizeof(model));
    
    printf("\n========================================\n");
    printf("   ALBEDRIO SECURITY - SALK MOBILE      \n");
    printf("========================================\n");
    printf("[+] Identidad: %s\n", model);
    printf("[+] Resonancia: %s\n", serial);
    
    if (getuid() == 0) {
        printf("[!] ESTADO: PRIVILEGIOS DE ROOT DETECTADOS\n");
    } else {
        printf("[*] ESTADO: EJECUCIÓN EN MODO USUARIO\n");
    }
    printf("========================================\n\n");
    
    return 0;
}
