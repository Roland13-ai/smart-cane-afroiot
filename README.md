# Smart Cane — AfroIoT

## Goal
An assistive smart cane for visually impaired users, designed to increase
independence in daily mobility. The cane detects nearby obstacles and
alerts the user through sound and vibration.

## How it works

- *HC-SR04 ultrasonic sensor* measures the distance to the nearest
  obstacle (trig = pin 9, echo = pin 10)
- *Active buzzer* (pin 11) and *vibration motor* (pin 12) provide
  dual feedback — sound and haptic — so the alert is perceivable even
  in noisy environments
- Adjustable detection range: 50 cm, 100 cm, or 200 cm (seuilAlerte)
- *Proportional alert speed*: the closer the obstacle, the faster the
  beep/vibration pulse, using map() to scale distance into a beep
  interval — giving the user a graded sense of proximity, not just a
  binary alert

## Code

→ [View source code](smart_cane.ino)

## Simulation

→ [Try it live on Wokwi](https://wokwi.com/projects/472290495355367425)

Tested and validated in simulation: with the obstacle set at 34 cm, the
alert pulses noticeably faster than at 80 cm — confirming the proportional
alert logic (map()-based beep speed) behaves as intended. No alert is
triggered above the 100 cm threshold.

## Hardware
- Arduino Uno (ATmega328P)
- HC-SR04 ultrasonic distance sensor
- Active buzzer
- Vibration motor
- Power source (battery pack, to be defined for wearable integration)

## Status
- [x] Core detection and alert logic written
- [x] Logic validated in simulation (Wokwi) — confirmed proportional
      alert speed and correct threshold behavior
- [ ] Physical prototype (cane housing + component mounting)
- [ ] Field testing with end users
- [ ] Timeout safeguard on pulseIn() to prevent blocking on sensor
      read failure

## Tools
Arduino IDE · Wokwi · C++ (Arduino framework)
