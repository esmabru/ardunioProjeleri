//Apartman otomatı
int pir=2;
int kirmizi=7;
int deger=0;

void setup()
{
  pinMode(kirmizi,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop()
{
  deger=digitalRead(pir);
  Serial.println(deger);
  
  if(deger==HIGH){
  digitalWrite(kirmizi,HIGH);
   delay(50000);
  }
  else
  digitalWrite(kirmizi,LOW);
  
  delay(1000); 
}
/* Sistem,yalnızca ortam karanlık olduğunda ve hareket algılandığında LED lambayı (veya ampulü) belirli bir süre için yakar.
Böylece gereksiz elektrik tüketiminin önüne geçilir.*/
int ldr=A0;
int led=7;
int pir=2;
int deger=0;
int ldr_deger;


void setup()
{
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop()
{
  deger=digitalRead(pir);
  Serial.println(deger);
  ldr_deger=analogRead(ldr);
  Serial.println(ldr_deger);

  //Eğer hareket algılanıyorsa ve ortam karanlıksa led yanar
  if((deger==HIGH) && (ldr_deger>500)){
  digitalWrite(led,HIGH);
  delay(5000);
  }
  else
  digitalWrite(led,LOW);
}
//Hareket Sensörü İle Servo Motor Kontrolü
#include<Servo.h>
Servo motor;
int pir=3;
int deger=0;


void setup()
{
  motor.attach(9);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Motor hali hazırda 0 derecede beklesin
  motor.write(0);
  deger=digitalRead(pir);
  Serial.println(deger);

  //Eğer hareket varsa servo motor 90 derece dönsün
  if(deger==HIGH){
  motor.write(90);
   delay(2000);
  }
  else
  motor.write(0);
}
