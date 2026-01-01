const byte ledPins[] = {21, 20, 19}; // define r, g, b
const byte chns[] = {0, 1, 2}; // define the pwn channels

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  for (int i = 0; i < 3; i++) {
    ledcAttachChannel(ledPins[i], 1000, 8, chns[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  const uint resolution = 256;
  const uint looptime = 5120;
  for (uint i = 0; i < resolution; i++) {
    setColour(i, resolution);
    delay(looptime / resolution);
  }
}

void setColour(uint x, const uint resolution) {
  x = x % resolution;
  float res = (float) resolution;

  float multiplier = -255.0f / (res * res / 9.0f); // this multiplier transforms the quadratics to be between 0 and 255

  float translated_x = (x - res / 3);
  if (translated_x < 0) translated_x += res;

  float r = multiplier * (translated_x - res / 3) * (translated_x - res);
  float g = multiplier * x * (x - 2 * res / 3);
  float b = multiplier * (x - res / 3) * (x - res);

  uint red = (int) constrain(r, 0, 255);
  uint green = (int) constrain(g, 0, 255);
  uint blue = (int) constrain(b, 0, 255);

  // Serial.print("\r\nx: ");
  // Serial.print(x);
  // Serial.print("\r\nRed: ");
  // Serial.print(red);
  // Serial.print("\r\nGreen: ");
  // Serial.print(green);
  // Serial.print("\r\nBlue: ");
  // Serial.print(blue);

  // actually write to the pins
  ledcWrite(ledPins[0], 255 - red);
  ledcWrite(ledPins[1], 255 - green);
  ledcWrite(ledPins[2], 255 - blue);
}
