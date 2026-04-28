# Albedrío Security Mobile Sentinel
### Advanced Native Protection for Android (AArch64 / ARMv7)

**Built in Pure C - Zero Dependencies - Injection Ready.**

---

## 📜 Philosophy
Albedrío Security Mobile is a defensive-offensive suite designed to reclaim control of compromised Android devices. It bypasses traditional app sandboxing by operating as a native binary, allowing for deep process inspection and hardware-level resonance.

## ⚙️ Mobile Architecture

1.  **🔐 Mobile Resonance (SALK ARM):** Unlike x86, this engine merges `ro.serialno` and SoC properties to forge an immutable device identity.
2.  **🛡️ Sentinel Hunter Mode:** Real-time scanning of the `/proc` filesystem to identify and terminate remote control tools, RATs, and unauthorized shells (AnyDesk, TeamViewer, Metasploit, etc.).
3.  **🚀 Native Injection:** Compiled as a static binary to ensure compatibility across different Android distributions without needing external libraries.
4.  **🛰️ Mobile Petaboom:** A lightweight version of the saturation engine designed to disrupt the hacker's Command & Control (C2) connection directly from the mobile device.

## 🚀 Deployment
Since this is a native binary, it can be deployed via ADB or any privileged injection method:

1. **Push the binary to the device:**
   ```bash
   adb push bin/salk_mobile_unified /data/local/tmp/
   ```
2. **Set permissions and execute:**
   ```bash
   adb shell
   chmod +x /data/local/tmp/salk_mobile_unified
   /data/local/tmp/salk_mobile_unified
   ```

---
---

# Albedrío Security Mobile Sentinel [ESPAÑOL]
### Protección Nativa Avanzada para Android

## 📜 Filosofía
Ecosistema diseñado para recuperar dispositivos Android comprometidos mediante inyección de binarios puros.

## ⚙️ Pilares Móviles
1. **Resonancia ARM:** Identidad forjada en el serial de hardware del teléfono.
2. **Modo Cacería:** Escaneo y aniquilación de procesos de espionaje en tiempo real.
3. **Inyección Nativa:** Binarios estáticos de alta compatibilidad.
4. **Petaboom Móvil:** Capacidad de saturación de red desde la palma de tu mano.

---

📧 **Contact / Donations:** esmeydub@gmail.com
