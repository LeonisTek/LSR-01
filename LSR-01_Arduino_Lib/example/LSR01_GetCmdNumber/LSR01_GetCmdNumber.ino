//
//	本範例是使用Arduino透過LSR-01 AI語音辨識模組進行語音命令辨識,
//	並進行D13亮滅控制,當使用者下[命令1]時,D13 LED燈亮起,下[命令2]時,D13 LED燈熄滅。
//
//	接線方式: 
//	LSR-01 模組		Arduino模組
//		5V 		->		5V
//		RX1		->		D12
//		TX1		->		D11
//		GND		->		GND
//
//	使用的函式庫: https://github.com/LeonisTek/LSR-01
//
//	立辰科技 28.JAN.2025
//


#include "LSR01.h"

//定義LSR01接腳RX,TX
LSR01 LSR(11,12); 

void setup() {
  
  //初始化 LSR01模組
  LSR.begin();
  
  pinMode(13,OUTPUT);

}
//宣告用來存放回傳聲控命令的變數
uint8_t LSR01_CMD=0;

void loop() {

  
  //當GetCMD為1時 代表有讀到新的聲控命令(0為沒有讀到新命令),並把命令號碼帶入LSR01_CMD中
  if(LSR.GetCMD(&LSR01_CMD) == 1){
	
    Serial.println(LSR01_CMD);//顯示讀到的命令編號
  }
  
  //取得命令編號1,預設命令為"打開第一接點",
  //編號列表與學習命令順序一致,或參考Github連結
  if(LSR01_CMD == 1){//判斷命令編號,並拿來控制D13 LED
    digitalWrite(13,1);
  }else if(LSR01_CMD == 2){// 取得命令編號2,預設定令為"關閉第一接點"
    digitalWrite(13,0);
  }

}
