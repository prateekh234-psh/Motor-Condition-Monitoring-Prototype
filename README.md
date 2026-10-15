# Wireless Industrial Motor Condition Monitoring

**Status:** Hardware prototype / early-stage exploration  
**Hardware:** Arduino UNO, ACS712 current sensor; piezo sensor and ESP32 can be added as the prototype develops.

## Aim
Collect motor-current readings and explore whether operating conditions produce distinguishable readings. This is a learning prototype, not a validated industrial fault-detection system.

## Current starter scope
- Read the ACS712 analog output
- Estimate current using a configurable zero-current voltage and sensor sensitivity
- Print readings over Serial Monitor

## Wiring (ACS712 module)
- VCC → Arduino 5V (check your specific module rating)
- GND → Arduino GND
- OUT → Arduino A0
- Route the motor supply conductor through the sensor's current path as specified by the module manufacturer.
- Use an appropriate motor supply and safe wiring. Do not power a motor from an Arduino I/O pin.

## Run
1. Open `motor_current_monitor.ino` in Arduino IDE.
2. Confirm the sensor's sensitivity from its datasheet/module marking.
3. Upload and open Serial Monitor at 9600 baud.
4. Calibrate the zero-current voltage for your actual setup before interpreting values.

## Limitations
- Sensor offset and noise affect readings; calibration is required.
- Current alone cannot reliably diagnose all motor faults.
- Do not claim predictive maintenance or fault detection until tested against labelled operating conditions.
