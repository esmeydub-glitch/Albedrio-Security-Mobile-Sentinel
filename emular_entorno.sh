#!/bin/bash
# EMULADOR DE ENTORNO ANDROID PARA SALK
# Este script simula las propiedades de un dispositivo móvil para pruebas de inyección.

echo ">>> Iniciando Laboratorio de Simulación Android <<<"

# Simulamos el comando getprop de Android
function getprop() {
    case $1 in
        "ro.serialno") echo "SALK-SIM-777-XYZ" ;;
        "ro.product.model") echo "ALBEDRIO-MOBILE-PRO" ;;
        *) echo "" ;;
    esac
}

export -f getprop

# Creamos una terminal simulada
echo "[+] Entorno de Inyección Listo."
echo "[+] Simulación: Motorola / Android 14"
echo "------------------------------------------------"

# Ejecutamos el binario móvil dentro del entorno simulado
./bin/salk_mobile

echo "------------------------------------------------"
echo ">>> Simulación Finalizada <<<"
