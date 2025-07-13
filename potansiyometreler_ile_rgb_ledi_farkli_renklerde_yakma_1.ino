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