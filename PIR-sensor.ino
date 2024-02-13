const int PIR_PIN = 13;   // PIR sensor input pin  //connect + pin to 5v power supply only on esp32 board
const int LED_PIN = 14;   // LED output pin
const int DELAY_TIME = 1000;  // Delay time between readings in milliseconds

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("Motion Detection with PIR Sensor");
}

void loop() {
  if (motionDetected()) {
    turnOnLED();
    Serial.println("Motion detected!");
    delay(DELAY_TIME);
  } else {
    turnOffLED();
    Serial.println("No motion detected.");
    delay(DELAY_TIME);
  }
}

bool motionDetected() {
  return digitalRead(PIR_PIN) == HIGH;   // if PIR-PIN is high return true if Low return false
}

void turnOnLED() {
  digitalWrite(LED_PIN, HIGH);
}

void turnOffLED() {
  digitalWrite(LED_PIN, LOW);
}
