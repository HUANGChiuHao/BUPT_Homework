#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

const int buttonPin = 2;
const int buttonState = 0;
const int motorPin = 3;
const int pinBuzzer = 4; 
const int in_1 = 8 ;
const int in_2 = 9 ;

void setup()
{
  //开门
   pinMode(ledPin, OUTPUT);
   pinMode(buttonPin, INPUT);
    pinMode(pwm,OUTPUT) ;
   pinMode(in_1,OUTPUT) ;
   pinMode(in_2,OUTPUT) ;
   
  //显示
  Serial.begin(9600);
  Serial.println("OLED FeatherWing test");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  
  //报警
  pinMode(pinBuzzer, OUTPUT);
}

void loop()
{
  //开门
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH)
    {
      digitalWrite(in_1,HIGH) ;
      digitalWrite(in_2,LOW) ;
      analogWrite(pwm,255) ;
      delay(2000) ;
      digitalWrite(in_1,HIGH) ;
      digitalWrite(in_2,HIGH) ;
      delay(50000) ;
      digitalWrite(in_1,LOW) ;
      digitalWrite(in_2,HIGH) ;
      delay(2000) ;
   }
   
  //显示
 if (buttonState == HIGH)
    {
      display.println("舱门已开，请尽快取药。");
      display.display();
    }
    
  //报警
  if (buttonState == HIGH)
    {
     delay(10000);
     long frequency = 300;
     tone(pinBuzzer, frequency );
     delay(1000);
     noTone(pinBuzzer);
     delay(2000);
    }
}
