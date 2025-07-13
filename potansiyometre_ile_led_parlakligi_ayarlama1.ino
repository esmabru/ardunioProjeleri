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
