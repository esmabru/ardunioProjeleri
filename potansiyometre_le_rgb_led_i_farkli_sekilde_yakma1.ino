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