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

























