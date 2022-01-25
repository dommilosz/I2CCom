#include "I2CCom.h"
I2CCom_Slave I2CCom(24,120);

void setup() {
  // put your setup code here, to run once:
  I2CCom.begin();
  I2CCom._wire->onReceive(receiveEvent);
  I2CCom._wire->onRequest(requestEvent);
  Serial.begin(57600);
}

uint8_t data[3];

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  data[0] = 65;
  data[1] = 66;
  data[2] = 0;
  Serial.write((const uint8_t *)data,3);
  I2CCom.Interrupt(69, data, 3);

  Serial.println(I2CCom.address);
}

void receiveEvent()
{
  if (!I2CCom.receiveEvent()) {

  }
}

void requestEvent()
{
  if (!I2CCom.requestEvent()) {

  }
}
