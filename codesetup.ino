#include <IRremote.h>
#include <U8glib.h>
#define human 4
#define ok    33478695      //数字0
#define a     33456255      //数字1
#define b     33439935      //数字2
#define c     33472575      //数字3
#define d     33431775      //数字4
#define e     33464415      //数字5
#define f     33448095      //数字6
#define g     33480735      //数字7
#define h     33427695      //数字8
#define i     33460335      //数字9

#define INTERVAL_LCD    20      
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long lcd_time = millis();                 //OLED刷新时间计时器
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);     //设置OLED型号  
//-------字体设置，大、中、小
#define setFont_L u8g.setFont(u8g_font_7x13)
#define setFont_M u8g.setFont(u8g_font_fixed_v0r)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_SS u8g.setFont(u8g_font_fub25n)

bool humanHotState = false;


    
void setup() {
  Serial.begin(9600);
  pinMode(human, INPUT);
  irrecv.enableIRIn();
  Serial.println("Start working");
}


  void loop() {
    humanHotState = digitalRead(human);
  if (humanHotState) 
    {  setFont_L;
    u8g.setPrintPos(50, 16);
      u8g.print("please enter the code");
  if (irrecv.decode(&results)) 
  {
    switch(results.value){
      case a :
    Serial.print("1");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("1");
      break;
      case b :
    Serial.print("2");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("2");
      break ;
      case c :
    Serial.print("3");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("3");
      break;
      case d :
    Serial.print("4");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("4");
      break;
      case e :
    Serial.print("5");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("5");
      break;
      case f :
    Serial.println("6");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("6");
      break;
      case g :
    Serial.println("7");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("7");
      break;
      case h :
    Serial.print("8");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("8");
      break;
      case i :
    Serial.print("9");
    setFont_L;
    u8g.setPrintPos(4, 16);
    u8g.print("9");
      break;
  }
  irrecv.resume(); //接收下一个值
  }
    }
  }
/*
#include <IRremote.h>
#include <U8glib.h>
#define INTERVAL_LCD             20             //定义OLED刷新时间间隔  
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long lcd_time = millis();                 //OLED刷新时间计时器
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);     //设置OLED型号  
//-------字体设置，大、中、小
#define setFont_L u8g.setFont(u8g_font_7x13)
#define setFont_M u8g.setFont(u8g_font_fixed_v0r)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_SS u8g.setFont(u8g_font_fub25n)
void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn(); // 启动红外解码
    Serial.println("Initialisation complete.");
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    u8g.firstPage();
    do {
        setFont_L;
        u8g.setPrintPos(4, 16);
        u8g.print(results.value,HEX);
    }while( u8g.nextPage() );
    irrecv.resume();  //接收下一个值
  }
}
*/
