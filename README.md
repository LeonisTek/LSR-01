# LSR-01 離線式語音辨識模組 

![lsr01.png](https://github.com/LeonisTek/LSR-01/blob/main/PIC/lsr01.png)

## 簡介
LSR-01是一款透過內建類神經網路處理器及32-bit CPU的AI語音辨識模組,搭載預先訓練的語言模型,不須連接網路即可離線使用,可達到即時語音辨識目的。
本模組具有可自定義命令詞功能,支援中文、台語、英文等語言,無須編寫程式,透過口說方式即可達到自定義命令詞的功能。


## 模組特色
* 支援透過口說進行自定義喚醒詞及命令詞
* 自定義命令支援中文、台語、客語、英語、日語等等其他語言
* 支援Arduino、Makeblock環境,附有函示庫
* 5個實體輸出接腳可透過命令進行開關控制(可自定義命令詞)
* 額外10個自定義控制命令,可透過通訊接口輸出命令
* 支援回覆音切換、靜音模式、自動休眠模式等設定
* 支援Modbus RTU工業通訊介面,可擴充工業8路繼電器模組
* 所有IO具備保護電路,不易受靜電、突波影響而損壞
* 電源輸入具備防反接及抗突波電路

## 模組硬體說明



| 標示    |    名稱   | 標示 |    功能    |    備註    |
| -------- | -------- |-------- | -------- | -------- |
| 1     | 外接麥克風座    | | 外接電容式麥克風(選接)     | 當模組安裝於不易收音處可外接麥克風 |
| 2     | 外接喇叭座    | |Text     | 喇叭4歐姆下最大輸出功率1.5W |
| 3     | 內建麥克風    | |Text     |  |
| 4     | 電源輸入    | 5V|  5V電源    |  |
|       |            | GND  |電源接地|  |
| 5     | 輸出接點     | 5V | 5V電源   |  |
|       |          | D0 | 輸出接腳1   |  |
|       |          | D1 | 輸出接腳2   |  |
|       |          | D2 | 輸出接腳3   |  |
|       |          | D3 | 輸出接腳4   | 開機時會維持約1秒為高電位,開機後恢復 |
|       |          | D4 | 輸出接腳5   | 開機時會維持約1秒為高電位,開機後恢復 |
|       |          | GND | 電源接地   |  |
| 6     | 輸出接腳狀態LED燈 | D0~D4 |  D0~D4的輸出狀態指示燈  |  |
| 7     | UART1通訊介面    | 5V |  5V電源  |  |
|       |                | RX1  |RX| 3.3V準位 |
|       |                | TX1  |TX| 3.3V準位 |
|       |                | GND  |電源接地|  |
| 8     | UART0通訊介面     | Text |    |  |
|       |                | RX0  |RX| 3.3V準位 |
|       |                | TX0  |TX| 3.3V準位 |
|       |                | GND  |電源接地|  |



## 命令使用方式
1. ### 喚醒機制及控制方式
模組使用時需先透過喚醒命令呼叫,讓模組進入喚醒狀態後才可進行控制命令呼叫,

預設喚醒命令:
	
    聲控助理

當下喚醒命令後,模組會使用語音回覆:” 請下命令”,此時即可下控制命令進行控制,舉例增加回覆音量的功能控制命令，其它命令可參考:命令清單:

	音量增加

此時,模組回覆:”音量已增加”並且提高模組回覆音量。

當若需要下其它命令時,可連續進行命令呼叫,當超過30秒都沒有呼叫新命令時,系統進入休眠模式,命且回覆:”進入休眠模式”,或是手動下休眠命令,也能讓模組直接進入休眠模式:

預設休眠命令:

	休眠模式

若不需要30秒後自動休眠功能時,可以透過命令進行開啟/關閉

設定自動休眠命令:

	自動休眠設定

若回覆:”已停用自動休眠” 代表已經停用,若再下一次自動休眠命令時,
會回覆:”已開啟自動休眠” 代表已經重新開啟自動休眠。



---

2. ### 回覆音設定
本模組於辨識成功時會播放回覆音,預設為人聲語音回覆,若不需要語音功能可進行回覆音設定或是靜音模式設定。
	
回覆音可設定為 人聲語音 及 提示音,其中提示音為”咚”聲,以下命令可進行設定:
	
	回覆音設定
	
當模組回覆”咚”一聲代表設為提示音,
當再下一次回覆音設定時會回覆”已切換為語音回覆”代表已切回語音回覆

如果要完全關閉回覆音,可以使用以下命令關閉回覆音:

	打開靜音模式
當下完命令後,模組不會回覆任何聲音,代表已經開啟靜音模式,
若要關閉靜音模式,請下以下命令即可關閉:

	關閉靜音模式

---

3. ### 自定義命令功能

本模組可進行喚醒命令及控制命令的自定義,在進行自定義命令學習時,請務必遵守以下原則:
		
    1. 請在安靜環境下進行學習
    2. 說出命令時請確保每個字清晰,勿連音
    3. 命令建議至少3字,並且使用音調有起伏的命令會使辨識度提高
    4. 如: 打開電燈、開啟電燈、開電燈
    5. 不同的自訂命令若太相近可能會學習失敗

1. #### 自訂喚醒命令

    **操作影片:**

    本模組總共可以自行定義2個喚醒命令,可透過以下命令進入喚醒詞學習模式:

        喚醒詞學習模式
    
    此時,模組回覆”請確保在安靜環境下進行喚醒命令學習，請說出要學習的喚醒命令” 後即可說出要學習的命令,若回覆”學習成功” 代表完成學習,若需要學習第二個喚醒命令,再下一次喚醒詞學習模式即可學習第二個

2. #### 自訂控制命令
    **操作影片:**
    
    本模組總共可以自行定義27個命令,學習順序依序為:
    
        5個實體接點開&關命令(每個接點各有開、關的命令,總共10個)
            預設命令為:打開第1接點、關閉第1接點....打開第2….依此類推至..關閉第5接點

        5個實體接點切換命令
	        預設命令為:切換第1接點...切換第2…..至 切換第5接點

        10個無實體接點的自訂命令
            預設命令為: 開啟第1自訂命令 … 關閉第1….至.. 關閉第5自訂命令

        2個全部打開、全部關閉命令
		    本命令可用來控制5個實體接點一起開啟或關閉

    可透過以下命令進入喚醒詞學習模式:
    
        命令詞學習模式
        
	進入學習模式時,請依照語音提示依序學習命令,若學習時發現命令說錯了可用以下命令來重新學習上     一個已學習完成的命令:
			
        重新學習
		
    若中途想退出學習,可下以下命令來退出學習模式,待下次重新進入學習時會從上次中斷處重新學習。
    
	    退出學習


3. #### 刪除命令
    若需要重新學習 **喚醒詞** 或 **命令詞** 可使用以下命令:

        刪除命令
        
	此時模組回覆:”請說刪除喚醒詞或是刪除命令詞來刪除命令” 若需要刪除 **喚醒詞** 請下:

	    刪除喚醒詞
    
    若需要刪除 **命令詞** 請下:
	
	    刪除命令詞

    若需要刪除 **喚醒詞** 及 **命令詞** 請下:
	
	    全部刪除

---
## 命令列表

待補上

## 使用範例:
### 範例1-內建輸出接腳直接輸出使用:

本模組具有5組輸出接腳可進行使用,可使用命令進行開/關或切換的動作,可直接控制繼電器模組來做  各種控制,如電燈、風扇等設備。

![lsr01_relay.png](https://github.com/LeonisTek/LSR-01/blob/main/PIC/lsr01_relay.png)

    註:D3及D4接腳於模組上電時會有大約1秒的時間為高電位,因此可能導致繼電器被開啟1秒,
    建議若不需用到3支以上接腳請優先使用D0~D2,或考慮改用其他方式
    (如Arduino讀取通訊方式或ModbusRTU通訊)。
    

### 範例2 -透過通訊-使用Arduino IDE
    
透過模組UART1通訊接口可與Arduino進行通訊,達到更多功能,本模組附有對應函式庫可進行使用 Github: https://github.com/LeonisTek/LSR-01

#### 接線圖:

![lsr01_nano.png]([https://hackmd.io/_uploads/Hy1ZrVUYJx.png](https://github.com/LeonisTek/LSR-01/blob/main/PIC/lsr01_nano.png))


#### 程式碼:

```
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
  
  //取得命令編號1,預設命令為"打開第1接點",
  //編號列表與學習命令順序一致,或參考Github連結
  if(LSR01_CMD == 1){//判斷命令編號,並拿來控制D13 LED
    digitalWrite(13,1);
  }else if(LSR01_CMD == 2){// 取得命令編號2,預設定令為"關閉第1接點"
    digitalWrite(13,0);
  }

}
```


### 範例3-透過通訊命令控制伺服馬達SG90-使用mBlock
本模組附有對應mBlock擴充庫,可相容mCore、Arduino Nano、UNO等開發版,可透過積木方式進行快速的功能設計。

#### 擴充庫安裝方式:
