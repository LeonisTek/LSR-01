/*
	Arduino library for LSR-01 AI Speech Recognition Module

	Designed by LEONIS TECHNOLOGY CO., LTD.  28.JAN.2025

*/

#ifndef LSR01_H

#define LSR01_H


#include <Arduino.h>
#include <SoftwareSerial.h>



class LSR01 {

public:

  LSR01(byte RX_PIN, byte TX_PIN);

  ~LSR01();
  void begin();

  byte GetCMD(uint8_t* voicecmd);
  
};

#endif