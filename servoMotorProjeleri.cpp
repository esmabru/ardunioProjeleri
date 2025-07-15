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
  sg90.write(92);
 
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
