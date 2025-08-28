//DC motorun ileri geri dönmesi
#define dc1 2
#define dc2 3
void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
}

void loop()
{
  digitalWrite(dc1, HIGH);
  digitalWrite(dc2, LOW);
  delay(1000);
  digitalWrite(dc2, HIGH);
  digitalWrite(dc1, LOW);
  delay(1000);
}

//2 dc motor hareketi
#define dc1 2
#define dc2 3
#define dc3 9
#define dc4 10
void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  pinMode(dc3, OUTPUT);
  pinMode(dc4, OUTPUT);
}

void loop()
{
  digitalWrite(dc1, HIGH);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, LOW);
  delay(2000);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, HIGH);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, LOW);
  delay(2000);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, HIGH);
  digitalWrite(dc4, LOW);
  delay(2000);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, HIGH);
  delay(2000); 
}

//Otomatik döner kapı yapımı
#define dc1 2
#define dc2 3
int pir=10;
int deger;

void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);  
}

void loop()
{
 deger=digitalRead(pir);
 
  Serial.println(deger);
  
  if(deger==HIGH){
  digitalWrite(dc1, HIGH);
  delay(1000);
  }
  else{
  digitalWrite(dc2, LOW);
  digitalWrite(dc1, LOW);
  delay(1000);
  }
}

//Engelden kaçan robot
int sol_g=2;
int sol_i=3;
int sag_g=9;
int sag_i=10;
int trigPin=11;
int echoPin=12;
float sure;
long mesafe;

void setup()
{
  pinMode(sol_g, OUTPUT);
  pinMode(sol_i, OUTPUT);
  pinMode(sag_g, OUTPUT);
  pinMode(sag_i, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  mesafe=(sure*0.034)/2;
  
  Serial.println(mesafe);
  
  
  if(mesafe<40){
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,HIGH);
  digitalWrite(sag_i,LOW);
  digitalWrite(sag_g,HIGH);
    
  delay(1500);
    
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,HIGH);
  digitalWrite(sag_i,HIGH);
  digitalWrite(sag_g,LOW);
    
  delay(2500);
  }
  
  else{
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,HIGH);
  digitalWrite(sag_i,LOW);
  digitalWrite(sag_g,HIGH);
  }
}

//Sıcaklık İle Fan Kontrol Etme
#define dc1 3
#define dc2 5
int tmp=A0;
int deger;

void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  pinMode(tmp, INPUT);
  Serial.begin(9600);  
}

void loop()
{
  deger=analogRead(tmp);
 Serial.println(deger);
  
  if(deger>200){
    digitalWrite(dc2,HIGH);
  }
  else
    digitalWrite(dc2,LOW);
}

//Butonlarla Dc Motoru İleri Geri Sürme
#define dc1 3
#define dc2 5
int buton1=11;
int buton2=12;
int buton3=13;
int sayac;


void setup(){
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
}

void ileri(){
digitalWrite(dc1,HIGH);
digitalWrite(dc2,LOW);
}
void geri(){
digitalWrite(dc1,LOW);
digitalWrite(dc2,HIGH);
}
void dur(){
digitalWrite(dc1,LOW);
digitalWrite(dc2,LOW);
}

void loop(){
  buton1=digitalRead(11);
  buton2=digitalRead(12);
  buton3=digitalRead(13);
  
  if(buton1==1)
    sayac=1;
  
  if(buton2==1)
    sayac=2;
  
  if(buton3==1)
    sayac=3;
  
  if(sayac==1) ileri();
  if(sayac==2) geri();
  if(sayac==3) dur();
  
  delay(10);
  
}

//Potansiyometre ile Dc Motorun Hızını Ayarlama
int pot=A0;
int potDeger=0;
int motorDeger=0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  potDeger=analogRead(pot);
  motorDeger=map(potDeger,0,1023,0,255);
  analogWrite(3,motorDeger);
  
  Serial.print("Potansiyometre= ");
  Serial.print(potDeger);
  Serial.print("\t motor= ");
  Serial.println(motorDeger);
  delay(2);
}

// Işık Takip Eden Robot
#define sol_g 2
#define sol_i 3
#define sag_g 4
#define sag_i 5
int ldr1=A0;
int ldr2=A1;
int deger1;
int deger2;
void setup()
{
  pinMode(sol_g, OUTPUT);
  pinMode(sol_i, OUTPUT);
  pinMode(sag_g, OUTPUT);
  pinMode(sag_i, OUTPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  deger1=analogRead(ldr1);
  deger2=analogRead(ldr2);
  
  Serial.print("LDR1= ");
  Serial.println(deger1);
  
  Serial.print("LDR2= ");
  Serial.println(deger2);
  
  deger1=map(deger1,0,512,0,1);
  Serial.print("LDR1map= ");
  Serial.println(deger1);
  
  deger2=map(deger2,0,512,0,1);
  Serial.print("LDR2map= ");
  Serial.println(deger2);
  
  if(deger1==1 && deger2==1){
  Serial.print("İleri");
  digitalWrite(sol_g,HIGH);
  digitalWrite(sol_i,LOW);
  digitalWrite(sag_g,HIGH);
  digitalWrite(sag_i,LOW);  
  delay(500);
  }
  if(deger1==0 && deger2==1){
  Serial.print("sağa");
  digitalWrite(sol_g,HIGH);
  digitalWrite(sol_i,LOW);
  digitalWrite(sag_g,LOW);
  digitalWrite(sag_i,HIGH);  
  }
  if(deger1==1 && deger2==0){
  Serial.print("sola");
  digitalWrite(sol_g,LOW);
  digitalWrite(sol_i,HIGH);
  digitalWrite(sag_g,HIGH);
  digitalWrite(sag_i,LOW);  
  delay(500);
  }
  if(deger1==0 && deger2==0){
  Serial.print("dur"); 
  digitalWrite(sol_g,LOW);
  digitalWrite(sol_i,LOW);
  digitalWrite(sag_g,LOW);
  digitalWrite(sag_i,LOW);  
  delay(500);
  }
}


