//Yangın alarmı 
int buzzer=7;
int tmp=A0;
int sicaklik;

void setup()
{
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 sicaklik=((analogRead(tmp)*4.88)-500)/10;
   
 Serial.println(sicaklik); 
  
  if(sicaklik>35){
  tone(buzzer,1000);
  delay(200);
  }
  else{
    noTone(buzzer);
    delay(200);
  }
}
