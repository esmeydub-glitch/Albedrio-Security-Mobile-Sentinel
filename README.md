# Albedrío Security Mobile Sentinel
### Advanced Native Protection for Android (AArch64 / ARMv7)

**Built in Pure C - Zero Dependencies - Injection Ready.**

---

## 📜 Philosophy
Albedrío Security Mobile is a defensive-offensive suite designed to reclaim control of compromised Android devices. It bypasses traditional app sandboxing by operating as a native binary, allowing for deep process inspection and hardware-level resonance.

## ⚙️ Mobile Architecture (Pure C / Native)

1.  **🔐 Mobile Resonance (SALK ARM):** Unlike x86, this engine merges `ro.serialno` and SoC properties to forge an immutable device identity.
2.  **🛡️ Sentinel Hunter Mode:** Real-time scanning of the `/proc` filesystem to identify and terminate remote control tools, RATs, and unauthorized shells.
3.  **🚀 Native Injection (No Java/No APK):** Compiled as a static ELF binary. It operates outside the Android Java Sandbox, providing direct access to Kernel syscalls.
4.  **🛰️ Mobile Petaboom:** A lightweight version of the saturation engine designed to disrupt the hacker's connection directly from the mobile hardware.

## 🚀 Tactical Deployment
The system is deployed as a standalone native binary via ADB or direct shell injection:

1. **Run the master injector:**
   ```bash
   ./inyectar.sh
   ```
2. **Manual execution (if needed):**
   ```bash
   /data/local/tmp/salk_mobile
   ```

---
---

# Albedrío Security Mobile Sentinel [ESPAÑOL]
### Protección Nativa Avanzada para Android

## 📜 Filosofía
Ecosistema diseñado para recuperar dispositivos Android comprometidos mediante inyección de binarios puros.

## ⚙️ Pilares Móviles (C Nativo / Sin Java)
1. **Resonancia ARM:** Identidad forjada en el serial de hardware del teléfono, ignorando variables de software.
2. **Modo Cacería:** Escaneo profundo de `/proc` para aniquilar procesos de espionaje en tiempo real.
3. **Inyección ELF (Sin APK):** El binario opera fuera del Sandbox de Java, permitiendo acceso directo a syscalls del Kernel.
4. **Petaboom Móvil:** Capacidad de saturación de red directa desde el hardware móvil.

## 🚀 Despliegue Táctico
El sistema se despliega como un binario nativo independiente:

```bash
./inyectar.sh
```

---

📧 **Contact / Donations:** esmeydub@gmail.com
