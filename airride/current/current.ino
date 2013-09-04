#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define RELAY1  6                        
#define RELAY2  7                        
#define RELAY3  8                        
#define RELAY4  9

int led = 13;
int var = 0;
int buttonState = 0;
const int buttonPin = 12;


LiquidCrystal_I2C lcd(0x3F,20,4);

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
  buttonState = digitalRead(buttonPin);
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  digitalWrite(RELAY1,HIGH);          // Turns Relay Off       
  digitalWrite(RELAY2,HIGH);
  digitalWrite(RELAY3,HIGH);
  digitalWrite(RELAY4,LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(7, 0);
  lcd.print("KEY ON");
  lcd.setCursor(6, 2);
  lcd.print("VER .21");
  delay (2000);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("AIRING UP");
  digitalWrite(RELAY1,LOW);
  delay (330);
  digitalWrite(RELAY1,HIGH);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(6, 0);
  lcd.print("LEVELING");
  digitalWrite(RELAY3,LOW);
  delay(1000);
  digitalWrite(RELAY3,HIGH);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(6, 0);
  lcd.print("Driving");
  lcd.setCursor(2, 1);
  lcd.print("Height Attained");
  delay(2000);
}

void loop()
{
  
  while(buttonState==1)
	{
    buttonState = digitalRead(buttonPin);
    lcdUpdate();
	}
  if (buttonState==0)
  {
      lcd.init();
      lcd.backlight();
      lcd.setCursor(7, 0);
      lcd.print("KEY OFF");
      digitalWrite(RELAY2,LOW);
      delay(5000);
      digitalWrite(RELAY4,HIGH); //arduino shutoff
  }
}

void lcdUpdate(){
      lcd.init();
      lcd.backlight();
      lcd.setCursor(3, 0);
      lcd.print("Air Ride Active");
      lcd.setCursor(3, 1);
      lcd.print("Drive Cycle");
      lcd.setCursor(15,1);
      lcd.print(var);
      var++;
}
