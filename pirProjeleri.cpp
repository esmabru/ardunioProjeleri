//Apartman otomatı
int pir=2;
int kirmizi=7;
int deger=0;

void setup()
{
  pinMode(kirmizi,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop()
{
  deger=digitalRead(pir);
  Serial.println(deger);
  
  if(deger==HIGH){
  digitalWrite(kirmizi,HIGH);
   delay(50000);
  }
  else
  digitalWrite(kirmizi,LOW);
  
  delay(1000); 
}
