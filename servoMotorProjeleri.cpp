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




















