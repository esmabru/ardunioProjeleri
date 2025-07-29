//RGB ile led yakma 
int kirmizi=10;
int mavi=9;
int yesil=8;
void setup()
{
  pinMode(kirmizi, OUTPUT);
   pinMode(mavi, OUTPUT);
   pinMode(yesil, OUTPUT);
}

void loop()
{
  analogWrite(kirmizi,255);
  analogWrite(mavi,0);
  analogWrite(yesil,0);
  delay(1000);
  
  analogWrite(kirmizi,0);
  analogWrite(mavi,255);
  analogWrite(yesil,0);
  delay(1000);
  
  analogWrite(kirmizi,0);
  analogWrite(mavi,0);
  analogWrite(yesil,255);
  delay(1000);  
}
//Rastgele renkte led yakma
int kirmizi=10;
int mavi=9;
int yesil=8;
int kirmizirandom;
int mavirandom;
int yesilrandom;
void setup()
{
  pinMode(kirmizi,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(yesil,OUTPUT);
}

void loop()
{
  //0-256 arasından rastgele sayı seçilir
  kirmizirandom=random(0,256);
  mavirandom=random(0,256);
  yesilrandom=random(0,256);
  
  analogWrite(kirmizi,kirmizirandom);
  analogWrite(mavi,mavirandom);
  analogWrite(yesil,yesilrandom);
  delay(100);
}
//RGB Led'i 3 Buton İle Farklı Renklerde Yakma
int kirmizi=5;
int mavi=6;
int yesil=7;
int buton1=8;
int buton2=9;
int buton3=10;
int kirmizideger=0;
int mavideger=0;
int yesildeger=0;

void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
  pinMode(buton3, INPUT);
}

void loop()
{
  if(digitalRead(buton1)==HIGH){
    delay(15);
    kirmizideger++;
    if(kirmizideger>255)
      kirmizideger=0;
  }
  if(digitalRead(buton2)==HIGH){
    delay(15);
    mavideger++;
    if(mavideger>255)
      mavideger=0;
  }
  if(digitalRead(buton3)==HIGH){
    delay(15);
    yesildeger++;
    if(yesildeger>255)
      yesildeger=0;
  }
  
  analogWrite(kirmizi,kirmizideger);
  analogWrite(mavi,mavideger);
  analogWrite(yesil,yesildeger);  
}
























