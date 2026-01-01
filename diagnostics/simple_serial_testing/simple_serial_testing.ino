void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("ESP32-S3-WROOM initliased");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Running time : %.1f s\r\n", millis() / 1000.0f);
  delay(1000);
}
