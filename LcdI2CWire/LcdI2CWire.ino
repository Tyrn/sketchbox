#include <Wire.h>

void WirebeginTransmission() { Wire.beginTransmission(0x27); }

const char *DecodeEndTransmission(unsigned errorCode) {
  switch (errorCode) {
  case 1:
    return "data too long to fit in transmit buffer";
  case 2:
    return "received NACK on transmit of address";
  case 3:
    return "received NACK on transmit of data";
  case 4:
    return "other error";
  case 5:
    return "timeout";
  default:
    return (errorCode ? "UNKNOWN" : "ZERO");
  }
}

void WireendTransmission(char *msg) {
  unsigned code = Wire.endTransmission();
  if (code > 0 && msg != NULL) {
    Serial.printf("endTransmission: \"%s\" %s\n", msg,
                  DecodeEndTransmission(code));
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Wire.begin();
  Wire.setClock(400000);
  WirebeginTransmission();
  Wire.write(0x01); // Clear display

  WireendTransmission("setup");
}

unsigned count = 0;

void loop() {
  Serial.printf(">>%d<<\n", count++);
  WirebeginTransmission();
  Wire.write(0x80); // Set cursor to the first line
  Wire.write("Hello, World!");
  WireendTransmission("loop");
  delay(3000);
}
