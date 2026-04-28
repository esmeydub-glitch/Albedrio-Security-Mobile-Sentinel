#!/bin/bash
# SIMULADOR DE COMBATE UNIFICADO (v1.0 Mobile)
echo ">>> Iniciando Laboratorio SALK MOBILE UNIFIED <<<"

# 1. Creamos al intruso
./bin/hacker_tool 1000 &
HACKER_PID=$!
echo "[!] ALERTA: Intruso en el sistema (PID: $HACKER_PID)"

# 2. Preparamos el entorno
export PATH=$PATH:./bin

# 3. Lanzamos el Sentinela Unificado en modo vigilancia
echo "[+] SALK: Iniciando Vigilancia y Cacería..."
./bin/salk_mobile_unified &
SALK_PID=$!

sleep 3

# 4. Verificación de bajas
if ps -p $HACKER_PID > /dev/null; then
    echo "[-] FALLO: El intruso evadió la vigilancia."
    kill $HACKER_PID
else
    echo "[V] ÉXITO: Intruso aniquilado por SALK Mobile."
fi

# 5. Probamos el brazo ofensivo
echo "[+] SALK: Probando brazo ofensivo (Petaboom)..."
./bin/salk_mobile_unified --attack

kill $SALK_PID 2>/dev/null
echo ">>> Operación de Simulación Finalizada <<<"
