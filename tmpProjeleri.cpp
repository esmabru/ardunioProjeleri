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

//Sıcaklık Sensörü İle Led Yakma
int kirmizi=5;
int mavi=6;
int yesil=7;
int tmp=A0;
int sicaklik;

void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(tmp, INPUT);
  Serial.begin(9600);
}

void loop()
{
 sicaklik=analogRead(tmp);
 Serial.println(sicaklik);
  
  if(sicaklik<30){
  digitalWrite(kirmizi,LOW);
  digitalWrite(mavi,LOW);
  digitalWrite(yesil,LOW);
  }
  else if(sicaklik>30 && sicaklik<100){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(mavi,LOW);
  digitalWrite(yesil,LOW);
  }
  else if(sicaklik>100 && sicaklik<200){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(mavi,HIGH);
  digitalWrite(yesil,LOW);
  }
  else if(sicaklik>200){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(mavi,HIGH);
  digitalWrite(yesil,HIGH);
  }
}
