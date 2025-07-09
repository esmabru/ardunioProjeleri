int arack=8;
int aracs=9;
int aracy=10;
int yayak=11;
int yayay=12;

void setup()
{
  pinMode(arack,OUTPUT);
  pinMode(aracs,OUTPUT);
  pinMode(aracy,OUTPUT);
  pinMode(yayak,OUTPUT);
  pinMode(yayay,OUTPUT); 
}

void loop()
{
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
delay(5000);
  
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
delay(2000);
  
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,LOW);
delay(5000);  
  
}