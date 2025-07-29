//Potansiyometre ile renk parlaklığı ayarlama
int led=9;
int pot=A0;
int pot1;
int pot2;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(pot2);
  pot1=analogRead(pot);
  pot2=map(pot1,0,1023,0,255);//map fonksiyonu pot1 değer aralığını 0-1023 ten 0-255 aralığına orantılı olarak dönüştürür
  
  delay(100);
  analogWrite(led,pot2);
}
//Potansiyometre ile ledi farklı renklerde yakma
int kirmizi=10;
int mavi=9;
int yesil=8;
int pot=A0;
int potdeger;

void setup()
{
  pinMode(kirmizi,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(potdeger);
  potdeger=analogRead(pot)/4;
  
  if(potdeger<70){
    analogWrite(kirmizi,0);
    analogWrite(mavi,0);
    analogWrite(yesil,0);
  }
  if(potdeger>70 && potdeger<120){
    analogWrite(kirmizi,255);
    analogWrite(mavi,0);
    analogWrite(yesil,0);
  }
  if(potdeger>120 && potdeger<180){
    analogWrite(kirmizi,0);
    analogWrite(mavi,255);
    analogWrite(yesil,0);
  }
  if(potdeger>180 && potdeger<256){
    analogWrite(kirmizi,0);
    analogWrite(mavi,0);
    analogWrite(yesil,255);
  }
}
//Birden fazla potansiyometre ile RGB ledi farklı renklerde yakma
int kirmizi=8;
int mavi=9;
int yesil=10;
int pot1=A0;
int pot2=A1;
int pot3=A2;
int potdegerkirmizi;
int potdegermavi;
int potdegeryesil;
void setup()
{
  pinMode(kirmizi,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
  pinMode(pot3,INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Analog değer 0-1023 arasında ancak led aralığı 0-256 bu sebeple analog değeri 4 e bölünür
  potdegerkirmizi=analogRead(pot1)/4;
  potdegermavi=analogRead(pot2)/4;
  potdegeryesil=analogRead(pot3)/4;
  
  analogWrite(kirmizi,potdegerkirmizi);
  analogWrite(mavi,potdegermavi);
  analogWrite(yesil,potdegeryesil);
  
  Serial.print("Kırmızı=");
  Serial.println(potdegerkirmizi);
  Serial.print("Mavi=");
  Serial.println(potdegermavi);
  Serial.print("Yeşil=");
  Serial.println(potdegeryesil);
  delay(2000);
  
} 

//Potansiyometre İle 3 Led'i Farklı Şekilde Yakma
int kirmizi=5;
int mavi=6;
int yesil=7;
int pot=A0;
int potdeger;
void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  potdeger=analogRead(pot);
  Serial.println(potdeger);
  
  if(potdeger<250){//potdeger 250 den küçükse hiçbir ledi yakma
    digitalWrite(kirmizi,LOW);
    digitalWrite(mavi,LOW);
    digitalWrite(yesil,LOW);
  }
  if(potdeger>250){//potdeger 250 den büyükse sadece kırmızı ledi yak
    digitalWrite(kirmizi,HIGH);
    digitalWrite(mavi,LOW);
    digitalWrite(yesil,LOW);
  }
   if(potdeger>500){//potdeger 500 den büyükse kırmızı ve mavi ledi yak
    digitalWrite(kirmizi,HIGH);
    digitalWrite(mavi,HIGH);
    digitalWrite(yesil,LOW);
  }
  if(potdeger>750){//potdeger 750 den büyükse hepsini yak
    digitalWrite(kirmizi,HIGH);
    digitalWrite(mavi,HIGH);
    digitalWrite(yesil,HIGH);
  }
  
}















