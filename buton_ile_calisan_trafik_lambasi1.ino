int arack=6;
int aracs=7;
int aracy=8;
int yayak=9;
int yayay=10;
int buton=5;
int butondurum=0;
void setup()
{
  pinMode(arack,OUTPUT);
  pinMode(aracs,OUTPUT);
  pinMode(aracy,OUTPUT);
  pinMode(yayak,OUTPUT);
  pinMode(yayay,OUTPUT);
  pinMode(buton,INPUT);
}

void loop()
{
  butondurum=digitalRead(buton);
  if(butondurum==HIGH){
    digitalWrite(arack,LOW);
    digitalWrite(aracs,LOW);
    digitalWrite(aracy,HIGH);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
    delay(1000);
    
    digitalWrite(arack,LOW);
    digitalWrite(aracs,HIGH);
    digitalWrite(aracy,LOW);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
    delay(2000);
    
    digitalWrite(arack,HIGH);
    digitalWrite(aracs,LOW);
    digitalWrite(aracy,LOW);
    digitalWrite(yayak,LOW);
    digitalWrite(yayay,HIGH);
    delay(10000);
    
    digitalWrite(arack,LOW);
    digitalWrite(aracs,HIGH);
    digitalWrite(aracy,LOW);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
    delay(1000);
  }
  else{
    digitalWrite(arack,LOW);
    digitalWrite(aracs,LOW);
    digitalWrite(aracy,HIGH);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
  }
}















