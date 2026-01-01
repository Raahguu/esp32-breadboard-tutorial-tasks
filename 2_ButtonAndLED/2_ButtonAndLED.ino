#define PIN_LED 2
#define PIN_BUTTON 13
#define CHECK_TIME 20

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  // For any debugging
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // invert LED polarity
  if (digitalRead(PIN_BUTTON) == LOW) {
    delay(CHECK_TIME);
    if (digitalRead(PIN_BUTTON) == LOW) {
      reverseGPIO(PIN_LED);
    }
  }

  // wait until ther button has been let go again
  while (digitalRead(PIN_BUTTON) == LOW);
  delay(CHECK_TIME);
}

void reverseGPIO(uint8_t pin) {
  digitalWrite(pin, !digitalRead(pin));
  Serial.println("reverse");
}