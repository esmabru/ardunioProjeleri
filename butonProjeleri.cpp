//Buton ile led yakma
int led=8;
int button=5;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop(){
  if(digitalRead(button)==HIGH){ 
    digitalWrite(led,HIGH);
  }
  if(digitalRead(button)==HIGH){
    digitalWrite(led,LOW);
  }
}
//Buton ile ledi açma kapama
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
//Buton ile kontrol edilen trafik lambası
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
