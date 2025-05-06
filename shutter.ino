// Arduino sketch to trigger shutter and notify host computer for TOF capture

const int shutterPin = 9; // TTL control pin for shutter (HIGH = open, LOW = closed)
const unsigned long tofDelay = 20; // TOF delay in milliseconds before image capture

void setup() {
  pinMode(shutterPin, OUTPUT);
  Serial.begin(9600);
  delay(2000); // Allow time for serial port to stabilize

  // Close MOT beam shutter (i.e. turn off trap)
  digitalWrite(shutterPin, LOW); // LOW = closed shutter (MOT beams off)
  Serial.println("Shutter closed, MOT off");

  // Wait for atoms to expand
  delay(tofDelay);

  // Notify computer to capture image
  Serial.println("SHUTTER_OPEN");

  // Optional: re-open MOT beam after a bit
  delay(100);
  digitalWrite(shutterPin, HIGH); // Re-open shutter
  Serial.println("Shutter reopened, MOT restored");
}

void loop() {
  // No continuous loop needed for one-shot TOF imaging
}