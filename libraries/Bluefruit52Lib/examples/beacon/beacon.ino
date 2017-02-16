/*********************************************************************
 This is an example for our nRF52 based Bluefruit LE modules

 Pick one up today in the adafruit shop!

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 MIT license, check LICENSE for more information
 All text above, and the splash screen below must be included in
 any redistribution
*********************************************************************/
#include <bluefruit.h>

uint8_t beaconUuid[16] = 
{ 
  0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78,
  0x89, 0x9A, 0xAB, 0xBC, 0xCD, 0xDE, 0xEF, 0xF0
};

// uuid, major, minor, rssi @1m
BLEBeacon beacon(beaconUuid, 0x0001, 0x0000, -54);

void setup() 
{
  Serial.begin(115200);

  Serial.println("Bluefruit52 Beacon Example");

  Bluefruit.begin();
  Bluefruit.setName("Bluefruit52");

  // Set up Advertising Packet
  setupAdv();

  // Start Advertising
  Bluefruit.startAdvertising();
}

void setupAdv(void)
{  
  Bluefruit.setAdvBeacon(beacon);

  // There is no room for Name in Advertising packet
  // Use Scan response for Name
  Bluefruit.addScanRespName();
}

void loop() 
{
  // Toggle both LEDs every 1 second
  digitalToggle(LED_BUILTIN);
  rtos_delay(1000);
}

