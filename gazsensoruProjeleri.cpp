//Gaz sensörü
int buzzer=13;
int gazSensoru=A0;
int deger;

void setup(){
pinMode(buzzer,OUTPUT);
pinMode(gazSensoru,INPUT); 
}
void loop(){
deger=analogRead(gazSensoru);
  if(deger>1000){
    tone(buzzer,1000);
     delay(1000);
  } else{
    noTone(buzzer);
  }
  delay(1000);
}
