#define PIN_LED 2
#define CHN     0     // define the pulse-width-modulation (pwn) channel
#define FRQ     1000  // define the pwn frequency
#define PWN_BIT 8     // define the pwn precision

void setup() {
  // put your setup code here, to run once:
  ledcAttachChannel(PIN_LED, FRQ, PWN_BIT, CHN);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++) { // make the LED fade in
    ledcWrite(PIN_LED, i);
    delay(10);
  }
  for (int i = 255; i > -1; i--) { // make the LED fade out
    ledcWrite(PIN_LED, i);
    delay(10);
  }
}
