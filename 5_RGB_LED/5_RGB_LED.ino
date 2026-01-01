const byte ledPins[] = {21, 20, 19}; // define red, green, and blue pins
const byte chns[] = {0, 1, 2}; // define pwm channels

void setup() {
  // put your setup code here, to run once:
  if (sizeof(chns) < sizeof(ledPins)) {
    Serial.println("There are not a corresponding number of channels for the LEDs");
    return;
  }

  for (int i = 0; i < sizeof(ledPins); i++) {
    ledcAttachChannel(ledPins[i], 1000, 8, chns[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t red = random(0, 256);
  uint8_t blue = random(0, 256);
  uint8_t green = random(0, 256);

  setColor(red, green, blue);
  delay(200);
}

void setColor(uint8_t red, uint8_t green, uint8_t blue) {
  // The LEDs are annode, so a low number will result in them being bright
  ledcWrite(ledPins[0], 255 - red);
  ledcWrite(ledPins[1], 255 - green);
  ledcWrite(ledPins[2], 255 - blue);
}
