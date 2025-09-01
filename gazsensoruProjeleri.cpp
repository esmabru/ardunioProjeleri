//Gaz sensörü
int buzzer=13;
int gazSensoru=A0;
int deger;

void setup(){
pinMode(buzzer,OUTPUT);
pinMode(gazSensoru,INPUT); 
}
void loop(){
deger=analogRead(gazSensoru);
  if(deger>1000){
    tone(buzzer,1000);
     delay(1000);
  } else{
    noTone(buzzer);
  }
  delay(1000);
}

//Lcd Ekranlı Gaz Alarmı
#include <LiquidCrystal.h>
int dcMotor=7;
int gazSensoru=A0;
int gazDegeri;
int buzzer=13;
int led=10;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
 lcd.begin(16, 2); 
 pinMode(gazSensoru,INPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(led,OUTPUT);
 lcd.begin(16,2); 
 Serial.begin(9600);
}

void loop()
{
 gazDegeri=analogRead(gazSensoru);
 Serial.println(gazDegeri);
  
  if(gazDegeri>150){
    digitalWrite(dcMotor,HIGH);
    digitalWrite(led,HIGH);
    tone(buzzer,1000);
  }
  else{
    digitalWrite(dcMotor,LOW);
    digitalWrite(led,LOW);
    noTone(buzzer);
  }
  lcd.setCursor(0,0);
  lcd.print("Gaz degeri= ");
  lcd.println(gazDegeri);
  delay(100);
}
