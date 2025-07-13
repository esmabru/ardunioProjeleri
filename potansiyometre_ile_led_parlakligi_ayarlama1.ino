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
  pot2=map(pot1,0,1023,0,255);
  
  delay(100);
  analogWrite(led,pot2);
}