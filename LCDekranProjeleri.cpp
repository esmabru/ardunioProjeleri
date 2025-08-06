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

//LCD Ekranda Değişen Yazı Yazdırma
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); 
}

void loop()
{
lcd.setCursor(5,0);
lcd.print("Merhaba");
delay(1000);
lcd.clear();//silme fonksiyonu
lcd.setCursor(1,0);
lcd.print("Nasil yardimci");
lcd.setCursor(3,1);
lcd.print("olabilirim?");  
delay(1000);
lcd.clear();
  
}
//LCD Ekranda Kayan Yazı Yazdırma
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
 
lcd.setCursor(0,1);
lcd.print("Merhaba,Nasil yardimci olabilirim?");

delay(50);
 
lcd.scrollDisplayLeft();//yazıların sol tarafa kaymasını sağlayan fonksiyon
   
}
//LCD ekranı * ile doldurma setcursor() fonksiyonu
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  lcd.setCursor(4,0);
  lcd.print("Esma Ebru");
  lcd.setCursor(5,1);
  lcd.print("Ozturk");
  
  delay(1000);
  lcd.clear();
  doldur();
}
  
  void doldur(){
  int katman=0;
    for(int i=0;i<8;i++){
    lcd.setCursor(0+katman,0);//sol üst köşe
    lcd.print("*");
    delay(50);
      
    lcd.setCursor(15-katman,0);//sağ üst köşe
    lcd.print("*");
    delay(50);
      
    lcd.setCursor(0+katman,1);//sol alt köşe
    lcd.print("*");
    delay(50);
      
    lcd.setCursor(15-katman,1);//sağ alt köşe
    lcd.print("*");
    delay(50);
    
    katman++;
    }
    lcd.clear();
  }

//LCD ekranı _ ile doldurma cursor() fonksiyonu
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  lcd.cursor();//imleç işaretini "_" aktifleştirir
}

void loop()
{
  lcd.setCursor(4,0);
  lcd.print("Esma Ebru");
  lcd.setCursor(5,1);
  lcd.print("Ozturk");
  
  delay(1000);
  lcd.clear();
  ekraniGez();
}
  
  void ekraniGez(){
  int katman=0;
    for(int i=0;i<8;i++){
    lcd.setCursor(0+katman,0);//sol üst köşe
    delay(50);
      
    lcd.setCursor(15-katman,0);//sağ üst köşe
    delay(50);
      
    lcd.setCursor(0+katman,1);//sol alt köşe
    delay(50);
      
    lcd.setCursor(15-katman,1);//sağ alt köşe
    delay(50);
    
    katman++;
    }
    lcd.clear();
  }

//LCD Ekrana Home Komutu ile Yazı Yazdırma
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  lcd.setCursor(5,0);
  lcd.print("Ebru");
  delay(500);
  
  lcd.home();//ekran imlecini sol üst köşeye taşır
  
  lcd.print("Esma");
  delay(500);
  
  lcd.clear();
  
}

// LCD Ekrana Yazıyı Harf Harf Yazdırma
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char veri[]={'e','s','m','a',' ','e','b','r','u'};

void setup()
{
  lcd.begin(16, 2); 
}

void loop()
{
  for(byte i=0;i<9;i++){
  //dizide gezinmemizi sağlayacak döngü
  //byte 0 ile 255 arasında sayı tutar
    lcd.write(veri[i]);
    /* write komutu iledizideki karakterler tek tek ekrana yazılır.
    Bu işlem print komutu ile tek tek de gerçekleştirilir.*/
    delay(100);
  }
  lcd.clear();
}

//Lcd Ekranda Yazıyı Yakıp Söndürme
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); 
  lcd.print("Esma Ebru");
}

void loop()
{
lcd.display();// Ekranı tekrar görünür yapar
 delay(500);
lcd.noDisplay();// Ekranı geçici olarak görünmez yapar
  delay(500);
}

















