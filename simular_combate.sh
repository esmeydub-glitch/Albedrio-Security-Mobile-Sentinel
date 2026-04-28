#!/bin/bash
echo ">>> Iniciando Laboratorio de Recuperación Motorola v1.5 <<<"
# 1. El hacker lanza su herramienta oculta
./bin/hacker_tool 1000 &
HACKER_PID=$!
echo "[!] ALERTA: Proceso Hacker detectado con PID: $HACKER_PID"

# 2. SALK inicia la cacería
export PATH=$PATH:./bin
./bin/sentinela_mobile &
SENTINEL_PID=$!

sleep 2

# 3. Verificación de bajas
if ps -p $HACKER_PID > /dev/null; then
    echo "[-] ERROR: El hacker ha evadido al Sentinela."
    kill $HACKER_PID
else
    echo "[V] VICTORIA: El intruso ha sido eliminado del sistema."
fi

kill $SENTINEL_PID 2>/dev/null
