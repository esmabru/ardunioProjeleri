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