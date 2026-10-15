// Basic ACS712 current-readout starter for Arduino UNO.
// Calibrate ZERO_CURRENT_VOLTAGE and SENSOR_SENSITIVITY for your module.
// This sketch reports measurements; it does not diagnose motor faults.

const int CURRENT_PIN = A0;
const float ADC_REFERENCE_V = 5.0;
const float ADC_COUNTS = 1023.0;

// Example values only: confirm your ACS712 variant and calibrate on your hardware.
// Typical nominal sensitivities: 5A=0.185 V/A, 20A=0.100 V/A, 30A=0.066 V/A.
const float ZERO_CURRENT_VOLTAGE = 2.50;
const float SENSOR_SENSITIVITY = 0.066; // Example for ACS712-30A

void setup() {
  Serial.begin(9600);
  Serial.println("ACS712 current monitoring starter");
  Serial.println("Calibrate offset and sensitivity before using readings.");
}

void loop() {
  const int samples = 100;
  long total = 0;

  for (int i = 0; i < samples; i++) {
    total += analogRead(CURRENT_PIN);
    delay(2);
  }

  float averageRaw = (float)total / samples;
  float sensorVoltage = averageRaw * ADC_REFERENCE_V / ADC_COUNTS;
  float currentA = (sensorVoltage - ZERO_CURRENT_VOLTAGE) / SENSOR_SENSITIVITY;

  Serial.print("Raw average: ");
  Serial.print(averageRaw, 1);
  Serial.print(" | Sensor voltage: ");
  Serial.print(sensorVoltage, 3);
  Serial.print(" V | Estimated current: ");
  Serial.print(currentA, 2);
  Serial.println(" A");

  delay(500);
}
