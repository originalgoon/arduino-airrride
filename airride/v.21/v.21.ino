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
  buttonState = digitalRead(buttonPin);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
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
  delay (1000);
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

void loop(){
  while (buttonState == 1) {
    buttonState = digitalRead(buttonPin);
    digitalRead(buttonPin);
    if (buttonState == 1) {
      buttonState = digitalRead(buttonPin);
      lcd.init();
      lcd.backlight();
      lcd.setCursor(4, 0);
      lcd.print("DATA LOGGING");
      var++;
      digitalWrite(led, LOW);
      lcd.setCursor(6, 1);
      lcd.print("CYCLE");
      lcd.setCursor(13,1);
      lcd.print(var);
      digitalWrite(led, HIGH);
      digitalRead(buttonPin);            
    }
    else {
      digitalRead(buttonPin);
      lcd.init();
      lcd.backlight();
      lcd.setCursor(7, 0);
      lcd.print("KEY OFF");
      digitalWrite(RELAY2,LOW);
      delay(5000);
      digitalWrite(RELAY4,HIGH); //arduino shutoff
    }
  }
  buttonState = digitalRead(buttonPin);
  digitalRead(buttonPin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(7, 0);
  lcd.print("DONE");
}





