#include<stdio.h>
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
#define j     33460335      //数字9

int n=0;
int code[3];
//code[n]=1;
 //定义数组和指针

int i ;
int x=random(0,9);
int y=random(0,9);
int z=random(0,9);
int mima[3]={x,y,z};
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
  Serial.begin(19200);
  pinMode(human, INPUT);
  irrecv.enableIRIn();
  Serial.println("Start working");
 u8g.firstPage();
    do {
        setFont_L;
        u8g.setPrintPos(4, 16);
        for(i=0;i<3;i++)
    {
    u8g.print(mima[i]);
    };
    }while( u8g.nextPage() );
    
}

  void loop() {
    humanHotState = digitalRead(human);
    
    
  if (humanHotState) 
    { 
      
  if (irrecv.decode(&results))  
  {
    
    switch(results.value){
      case a :
      code[n]=1 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=0;i<3;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case b :
      code[n]=2 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=0;i<3;i++)
    {
    Serial.print(code[i]);
    }
      break ;
      case c :
      code[n]=3 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=0;i<3;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case d :
      code[n]=4 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=1;i<4;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case e :
      code[n]=5 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=1;i<4;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case f :
      code[n]=6 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=1;i<4;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case g :
      code[n]=7 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=1;i<4;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case h :
      code[n]=8 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=1;i<4;i++)
    {
    Serial.print(code[i]);
    }
      break;
      case j :
    code[n]=9 ;
      n++ ;
      u8g.firstPage();
      do {
      setFont_L;
      u8g.setPrintPos(4, 16);
      for(i=0;i<3;i++)
    {
    u8g.print(code[i]);
    };}
      while( u8g.nextPage() );
      for(i=1;i<4;i++)
    {
    Serial.print(code[i]);
    }
      break;
  }
  irrecv.resume(); //接收下一个值
  }
    }

  
    if(code[1]==mima[1]&&code[0]==mima[0]&&code[2]==mima[2])
    {Serial.println("开锁");
    u8g.firstPage();
    do {
        setFont_L;
        u8g.setPrintPos(15,30);
        u8g.print("CORRECT!");
    }while( u8g.nextPage() );
    }
    
  }
