//16x2 LCD ekrana yazı yazdırma
#include<LiquidCrystal.h> //LCD kütüphanesi

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//bağlı olduğu pinler

void setup(){
  
lcd.begin(16,2);//16x2 lik ekran
  
lcd.setCursor(4,0);//hangi satır ve sütuna yazacağımızı belirtir   
lcd.print("Esma");    
lcd.setCursor(8,1);   
lcd.print("Ebru");  
  
}  

void loop(){   
  
}
//LCD ekrana mesafe sensörü değeri yazdırma
#include<LiquidCrystal.h>//LCD kütüphanesi

int trigPin=6;
int echoPin=7;
long sure;
float mesafe;

LiquidCrystal lcd(12,11,5,4,3,2);//bağlı olduğu pinler


void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin,LOW);

  sure=pulseIn(echoPin,HIGH);
  /*Sesin havadaki hızı yaklaşık 340 m/s yani 0.034 cm/µs.
  1 saniyede 34000 cm gittiği için → 1 mikrosaniyede 0.034 cm yol alır.
  Ölçülen süre gidiş ve dönüş süresi toplamı olduğu için, sadece tek yön mesafeyi bulmak için ikiye bölmemiz gerekir.*/
  mesafe=(sure*0.034)/ 2;

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  lcd.setCursor(0,0);
  lcd.print("Mesafe:  "); 
  lcd.print(mesafe); 
  lcd.print("cm");

  delay(300);
}
//Sıcaklık Değerini LCD Ekrana Yazdırma
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sicaklik;
int sicaklikPin=A0;

void setup()
{
lcd.begin(16, 2); 
Serial.begin(9600);
  
}

void loop()
{
  //sıcaklık ölçme işelemi
 sicaklik=((analogRead(sicaklikPin)*4.88)-500)/10;
   
 lcd.setCursor(0,0);
 lcd.print("Sicaklik");
 lcd.setCursor(0,1);
 lcd.print(sicaklik); 
  
  Serial.print(sicaklik);
  Serial.println("C");
  delay(500); 
  
}






















