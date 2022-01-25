#include "I2CCom.h"
I2CCom_Master I2CCom;

void setup() {
  // put your setup code here, to run once:
  I2CCom.begin();
  I2CCom.OnDeviceConnected = OnConnected;
  I2CCom.OnDeviceDisconnected = OnDisconnected;
  I2CCom.OnData = OnInterrupt;
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  I2CCom.ScanDevices();
}

void OnConnected(int address) {
  Serial.print("Connected: ");
  Serial.println(address);
}

void OnDisconnected(int address) {
  Serial.print("Disconnected: ");
  Serial.println(address);
}

void OnInterrupt(int addr,int type,int length){
  Serial.print("#######");
  Serial.print("INT: ");
  Serial.print(addr);
  Serial.print(" - ");
  Serial.println(type);

  uint8_t data[length];
  I2CCom.RequestData((int8_t *)data,length,addr,type);
  Serial.write(data,length);
}
