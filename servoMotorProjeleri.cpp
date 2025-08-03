//Servo motor çalıştırma kodu
#include<Servo.h>
//motoru kütüphaneden çağırıyoruz

Servo sg90;//nesne oluşturuyoruz
void setup()
{
  sg90.attach(9);//servo motorun bağlı olduğu pin
}
void loop()
{
  sg90.write(92);//92 derece dönme komutu
 
}
//Sürekli dönen servo motor kodu
#include<Servo.h>
int aci;
Servo motor;
void setup()
{
  motor.attach(9);//servo motorun bağlı olduğu pin
  Serial.begin(9600);
}

void loop()
{
  //0 dereceden 180 dereceye kadar döner
  for(aci=0;aci<=180;aci++){
    motor.write(aci);
    Serial.println(aci);
    delay(100);
  }
  //180 dereceden 0 dereceye geri döner
  for(aci=180;aci>=0;aci--){
    motor.write(aci);
    Serial.println(aci);
    delay(100);
  }
}
//Potansiyometre ile servo motor kontrolü
#include<Servo.h>

Servo motor;

int pot=A0;
int potdeger;

void setup()
{
 motor.attach(9);
  Serial.begin(9600);
}

void loop()
{
  potdeger=analogRead(pot);
  //map fonk. ile 0-1023 aralığını servo motorun dönme aralığı olan 0-180 e döüştürüyoruz
  potdeger=map(potdeger,0,1023,0,180);
  motor.write(potdeger);
  Serial.println(potdeger);
  delay(15);
}
//LDR ile servo motor kontrolü
#include<Servo.h>
Servo motor;

int ldr=A0;
int ldrdeger;
int aydinlikdeger=500;
int aci=0;

void setup()
{
  motor.attach(13);
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  motor.write(0);
}

void loop()
{
  ldrdeger=analogRead(ldr);
  Serial.println(ldrdeger);
  
  if(ldrdeger<aydinlikdeger){
    motor.write(180);
    delay(300);
  }
  else{
    motor.write(0);
  delay(300);
  }
}
//LDR Sensör ile Işığa Duyarlı Servo Motor
#include<Servo.h>

Servo motor;

int ldr=A0;
int ldrdeger;
int aci=0;

void setup()
{
  pinMode(ldr,INPUT);
  Serial.begin(9600);
  motor.attach(13);
  motor.write(aci);
}

void loop()
{
  ldrdeger=analogRead(ldr);
  ldrdeger=map(ldrdeger,0,1023,0,180);
  motor.write(ldrdeger);
  Serial.println(ldrdeger);
  delay(15);
}
//Çöp kutusu
#include <Servo.h>

Servo motor;
int trigPin=7;
int echoPin=8;

void setup()
{
  motor.attach(9);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  motor.write(0);
  Serial.begin(9600);
}

void loop()
{
  long sure;
  float mesafe;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  sure=pulseIn(echoPin,HIGH);
  mesafe = (sure * 0.034) / 2;
  

  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  if (mesafe<30) {
    motor.write(180);
  } 
  else {
    motor.write(0);
    delay(10);
  }
}

// 6 Tane Servo Motoru Arduinoya Bağlamak
#include<Servo.h>
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6;
  
int aci=0;  
void setup()
{
  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
  motor4.attach(8);
  motor5.attach(9);
  motor6.attach(10);
}

void loop()
{
  for(aci=0;aci<=180;aci++){
     motor1.write(aci);
     motor2.write(aci);
     motor3.write(aci);
     motor4.write(aci);
     motor5.write(aci);
     motor6.write(aci);
    delay(15);
  }
  for(aci=180;aci>=0;aci--){
     motor1.write(aci);
     motor2.write(aci);
     motor3.write(aci);
     motor4.write(aci);
     motor5.write(aci);
     motor6.write(aci);
    delay(15);
  }
}
// 3 Tane Potansiyometre İle 3 Servo Motor Kontrolü (Robot Kol)
#include<Servo.h>
Servo motor1;
Servo motor2;
Servo motor3;

int pot1=A0;
int pot2=A1;
int pot3=A2;
int potdeger1;
int potdeger2;
int potdeger3;


void setup()
{
  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
 
}

void loop()
{
  potdeger1=analogRead(pot1);
  potdeger1=map(potdeger1,0,1024,0,180);
  motor1.write(potdeger1);
  
  potdeger2=analogRead(pot2);
  potdeger2=map(potdeger2,0,1024,0,180);
  motor2.write(potdeger2);
  
  potdeger3=analogRead(pot3);
  potdeger3=map(potdeger3,0,1024,0,180);
  motor3.write(potdeger3);
  
  delay(100);
}

//Hafızalı Robot Kol Çalışması Servo Motor Mantığı
#include<Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;

int led1=8;
int led2=9;
int led3=10;
int led4=11;
int led5=12;

int buton1=4;
int buton2=3;

int pot1=A0;
int pot2=A1;
int pot3=A2;

int pot1deger;
int pot2deger;
int pot3deger;

int pot1aci;
int pot2aci;
int pot3aci;

int buton1deger=0;
bool buton2deger=false;

int potkayit1[]={1,1,1,1,1};
int potkayit2[]={1,1,1,1,1};
int potkayit3[]={1,1,1,1,1};


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
  
  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
  
  Serial.begin(9600);
  
}

void loop()
{
  // Potansiyometreleri oku ve servo açılarına çevir
  pot1deger=analogRead(pot1);
  pot1aci=map(pot1deger,0,1023,0,180);
  pot2deger=analogRead(pot2);
  pot2aci=map(pot2deger,0,1023,0,180);
  pot3deger=analogRead(pot3);
  pot3aci=map(pot3deger,0,1023,0,180);
  
  motor1.write(pot1aci);
  motor2.write(pot2aci);
  motor3.write(pot3aci);
  
   // --- Buton1 ile kayıt alma ---
  if(digitalRead(buton1)==HIGH){
    buton1deger++;
    switch(buton1deger){
     
      case 1:
      potkayit1[0]=pot1aci;
      potkayit2[0]=pot2aci;
      potkayit3[0]=pot3aci;
      digitalWrite(led1,HIGH);
      Serial.println("POT 1 KAYIT EDİLDİ");
      break;  
      case 2:
      potkayit1[1]=pot1aci;
      potkayit2[1]=pot2aci;
      potkayit3[1]=pot3aci;
      digitalWrite(led2,HIGH);
      Serial.println("POT 2 KAYIT EDİLDİ");
      break;  
      case 3:
      potkayit1[2]=pot1aci;
      potkayit2[2]=pot2aci;
      potkayit3[2]=pot3aci;
      digitalWrite(led3,HIGH);
      Serial.println("POT 3 KAYIT EDİLDİ");
      break;  
      case 4:
      potkayit1[3]=pot1aci;
      potkayit2[3]=pot2aci;
      potkayit3[3]=pot3aci;
      digitalWrite(led4,HIGH);
      Serial.println("POT 4 KAYIT EDİLDİ");
      break;  
      case 5:
      potkayit1[4]=pot1aci;
      potkayit2[4]=pot2aci;
      potkayit3[4]=pot3aci;
      digitalWrite(led5,HIGH);
      Serial.println("POT 5 KAYIT EDİLDİ");
      break;  
    }
  }
  
  // --- Buton2 ile oynatma ---
  if(digitalRead(buton2)==HIGH){
    for(int i=0;i<5;i++){
    motor1.write( potkayit1[i]);
    motor2.write(potkayit2[i]);
    motor3.write(potkayit3[i]);
    delay(1000);  
    }
  }
 delay(300); 
}



















