int measurePin = A0;
int ledPower = 2;

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

// --- CALIBRATION SETTINGS ---
// Enter the lowest value (Clean Air) from the Voltage column of your readings here.
// According to your data, the average is about 0.48V. 
// To be safe, let's keep it slightly lower, like around 0.45V.
float voc = 0.38; 

// Sensitivity (Standard value for Sharp sensors)
float K = 0.17; 
// ----------------------------

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  digitalWrite(ledPower, LOW); 
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin);

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH); 
  delayMicroseconds(sleepTime);

  // 1. Calculate Voltage
  calcVoltage = voMeasured * (5.0 / 1024.0);

  // 2. Calculate Dust Density (New equation)
  // Density = (Current Voltage - Clean Air Voltage) / Sensitivity
  // Multiply by 0.17 to get the mg/m3 value (Datasheet linear approximation)
  
  // Simplest method:
  dustDensity = (0.17 * calcVoltage) - (0.17 * voc);

  if (dustDensity < 0) {
    dustDensity = 0.00;
  }

  Serial.print("Raw: ");
  Serial.print(voMeasured);
  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);
  Serial.print("V - Dust Density: ");
  Serial.print(dustDensity);
  Serial.println(" mg/m3");

  delay(1000);
}