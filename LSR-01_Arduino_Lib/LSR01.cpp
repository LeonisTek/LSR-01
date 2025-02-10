/*
	Arduino library for LSR-01 AI Speech Recognition Module

	Designed by LEONIS TECHNOLOGY CO., LTD.  28.JAN.2025

*/
#include "LSR01.h"

// 定義變數
String LSR_M01_inputString = "";  // 用於存儲輸入字串
String LSR_M01_Voice_CMD = "";
bool LSR_M01_stringComplete = false;  // 用於指示是否收到完整字串

// 定義指向 LSR_M01_UART 的指標
SoftwareSerial* LSR_M01_UART=nullptr;

LSR01::LSR01(byte RX_PIN, byte TX_PIN) {

   // 創建 LSR_M01_UART 對象並初始化
  LSR_M01_UART = new SoftwareSerial(RX_PIN, TX_PIN);

   pinMode(RX_PIN, INPUT);
   pinMode(TX_PIN, OUTPUT);

}

void LSR01::Init() {


  LSR_M01_UART->begin(9600);
}

LSR01::~LSR01(){};

/*
  讀取聲控命令
  傳入值: 傳出命令編號的變數位址
  傳出值: 是否收到新命令
          0: 沒有收到新命令
          1: 有收到新命令
         -1: 收到的命令異常
*/
byte LSR01::GetCMD(uint8_t* voicecmd) {
  // 檢查軟體串列是否有資料
  while (LSR_M01_UART->available()) {
    
    char inChar = (char)LSR_M01_UART->read();  // 讀取一個字元
    Serial.print(inChar);

    if (inChar == '\r') {
      // 跳過回車符號
      continue;
    } else if (inChar == '\n') {
      // 結尾符號，完成字串
      LSR_M01_stringComplete = true;
    } else {
      // 將字元加入字串
      LSR_M01_inputString += inChar;
    }
  }
  if (LSR_M01_stringComplete) {
    LSR_M01_Voice_CMD = LSR_M01_inputString;
    LSR_M01_inputString = "";
    LSR_M01_stringComplete = false;

    //判斷指令內容
    if (LSR_M01_Voice_CMD == "#R10") {
      *voicecmd = 1;
    } else if (LSR_M01_Voice_CMD == "#R11") {
      *voicecmd = 2;
    } else if (LSR_M01_Voice_CMD == "#R20") {
      *voicecmd = 3;
    } else if (LSR_M01_Voice_CMD == "#R21") {
      *voicecmd = 4;
    } else if (LSR_M01_Voice_CMD == "#R30") {
      *voicecmd = 5;
    } else if (LSR_M01_Voice_CMD == "#R31") {
      *voicecmd = 6;
    } else if (LSR_M01_Voice_CMD == "#R40") {
      *voicecmd = 7;
    } else if (LSR_M01_Voice_CMD == "#R41") {
      *voicecmd = 8;
    } else if (LSR_M01_Voice_CMD == "#R50") {
      *voicecmd = 9;
    } else if (LSR_M01_Voice_CMD == "#R51") {
      *voicecmd = 10;
    } else if (LSR_M01_Voice_CMD == "#R60") {
      *voicecmd = 11;
    } else if (LSR_M01_Voice_CMD == "#R61") {
      *voicecmd = 12;
    } else if (LSR_M01_Voice_CMD == "#R70") {
      *voicecmd = 13;
    } else if (LSR_M01_Voice_CMD == "#R71") {
      *voicecmd = 14;
    } else if (LSR_M01_Voice_CMD == "#R80") {
      *voicecmd = 15;
    } else if (LSR_M01_Voice_CMD == "#R81") {
      *voicecmd = 16;
    } else if (LSR_M01_Voice_CMD == "#R90") {
      *voicecmd = 17;
    } else if (LSR_M01_Voice_CMD == "#R91") {
      *voicecmd = 18;
    } else if (LSR_M01_Voice_CMD == "#RA0") {
      *voicecmd = 19;
    } else if (LSR_M01_Voice_CMD == "#RA1") {
      *voicecmd = 20;
	}
	//------------------------------------------
	else if (LSR_M01_Voice_CMD == "#RB0") {
      *voicecmd = 21;
    } else if (LSR_M01_Voice_CMD == "#RB1") {
      *voicecmd = 22;
    } else if (LSR_M01_Voice_CMD == "#RC0") {
      *voicecmd = 23;
    } else if (LSR_M01_Voice_CMD == "#RC1") {
      *voicecmd = 24;
    } else if (LSR_M01_Voice_CMD == "#RD1") {
      *voicecmd = 25;
    } else if (LSR_M01_Voice_CMD == "#RD0") {
      *voicecmd = 26;
    } else if (LSR_M01_Voice_CMD == "#RE1") {
      *voicecmd = 27;
    } else if (LSR_M01_Voice_CMD == "#RE0") {
      *voicecmd = 28;
    } else if (LSR_M01_Voice_CMD == "#RF1") {
      *voicecmd = 29;
    } else if (LSR_M01_Voice_CMD == "#RF0") {
      *voicecmd = 30;
    }
	//------------------------------------------
	else if (LSR_M01_Voice_CMD == "#W00") {
      *voicecmd = 100;
    } else if (LSR_M01_Voice_CMD == "#S00") {
      *voicecmd = 101;
    } else if (LSR_M01_Voice_CMD == "#V++") {
      *voicecmd = 102;
    } else if (LSR_M01_Voice_CMD == "#V--") {
      *voicecmd = 103;
    } else if (LSR_M01_Voice_CMD == "#V00") {
      *voicecmd = 104;
    } else if (LSR_M01_Voice_CMD == "#V11") {
      *voicecmd = 105;
    
    } else {
      *voicecmd = -1;
      return -1;  // 如果未匹配，返回 -1 表示未知指令
    }
    return 1;
  }
  else{
    return 0;
  }
}