int leddurum=0;
int butondurum=0;
int x=0;
void setup()
{
  pinMode(8,OUTPUT);
  pinMode(5,INPUT);
}

void loop()
{
  butondurum=digitalRead(5);/*Bunu okuyor ve basılırsa 1 değerini
  basılmazsa 0 değerini atıyor*/
    if(butondurum==1 && x==0){
    x=1;
      if(leddurum==0)
      leddurum=1;
      else
      leddurum=0;
  }
  if(leddurum==1)
    digitalWrite(8,HIGH);
  else
    digitalWrite(8,LOW);
  if(butondurum==0 &&x==1){
    x=0;
  }
  delay(10);
}