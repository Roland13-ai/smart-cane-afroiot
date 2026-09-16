# Smart Cane — AfroIoT



![Status](https://img.shields.io/badge/status-active-brightgreen)




![License](https://img.shields.io/badge/license-MIT-blue)



## Overview
An assistive smart cane for visually impaired users that detects nearby obstacles and alerts them through sound and vibration.

## About
- **Problem it solves:** Visually impaired users need real-time obstacle awareness to move independently and safely.
- **Why I built it:** Hands-on embedded systems project applying ultrasonic sensing to a real assistive need, as part of AfroIoT Engineering.

## Key Features
- 🔊 Dual feedback — buzzer (sound) + vibration motor (haptic) — so alerts are perceivable even in noisy environments
- 📏 Detection threshold configurable in code (50 cm, 100 cm, or 200 cm)
- ⚡ Proportional alert speed — the closer the obstacle, the faster the beep/vibration pulse (via `map()`), giving a graded sense of proximity rather than a binary alert

## Hardware / Bill of Materials
| No | Component | Qty | Role |
|----|-----------|-----|------|
| 01 | Arduino Uno (ATmega328P) | 1 | Brain |
| 02 | HC-SR04 | 1 | Ultrasonic distance sensor |
| 03 | Active buzzer | 1 | Audio alert |
| 04 | Vibration motor | 1 | Haptic alert |
| 05 | Battery pack | 1 | Power (to be defined for wearable integration) |

## Tech Stack
`Arduino` `C++` `Wokwi`

## Simulation
→ [Try it live on Wokwi](https://wokwi.com/projects/472290495355367425)

Tested and validated: with the obstacle set at 34 cm, the alert pulses noticeably faster than at 80 cm — confirming the proportional alert logic behaves as intended. No alert is triggered above the detection threshold.

## Installation
1. Clone the repo
   ```bash
   git clone https://github.com/Roland13-ai/smart-cane-afroiot.git