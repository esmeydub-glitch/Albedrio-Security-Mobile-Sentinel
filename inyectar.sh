#!/bin/bash
# CARGADOR MAESTRO SALK MOBILE (Native Injection)
# Autor: Victor & Antigravity

echo ">>> Iniciando Inyección Nativa SALK <<<"

# 1. Detectar dispositivo
ADB_DEVICE=$(adb devices | grep -v "List" | head -n 1 | awk '{print $1}')

if [ -z "$ADB_DEVICE" ]; then
    echo "[-] Error: No se detectó ningún dispositivo vía ADB."
    exit 1
fi

echo "[+] Inyectando en dispositivo: $ADB_DEVICE"

# 2. Subir binario táctico
adb -s $ADB_DEVICE push bin/salk_mobile_unified /data/local/tmp/salk_mobile
adb -s $ADB_DEVICE shell chmod +x /data/local/tmp/salk_mobile

# 3. Ejecutar y Desprender
echo "[+] Lanzando SALK en el corazón del dispositivo..."
adb -s $ADB_DEVICE shell "nohup /data/local/tmp/salk_mobile > /dev/null 2>&1 &"

echo ">>> INYECCIÓN COMPLETADA. SALK está patrullando el Motorola. <<<"
