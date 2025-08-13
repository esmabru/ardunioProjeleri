//DC motorun ileri geri dönmesi
#define dc1 2
#define dc2 3
void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
}

void loop()
{
  digitalWrite(dc1, HIGH);
  digitalWrite(dc2, LOW);
  delay(1000);
  digitalWrite(dc2, HIGH);
  digitalWrite(dc1, LOW);
  delay(1000);
}

//2 dc motor hareketi
#define dc1 2
#define dc2 3
#define dc3 9
#define dc4 10
void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  pinMode(dc3, OUTPUT);
  pinMode(dc4, OUTPUT);
}

void loop()
{
  digitalWrite(dc1, HIGH);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, LOW);
  delay(2000);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, HIGH);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, LOW);
  delay(2000);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, HIGH);
  digitalWrite(dc4, LOW);
  delay(2000);
  digitalWrite(dc1, LOW);
  digitalWrite(dc2, LOW);
  digitalWrite(dc3, LOW);
  digitalWrite(dc4, HIGH);
  delay(2000); 
}

//Otomatik döner kapı yapımı
#define dc1 2
#define dc2 3
int pir=10;
int deger;

void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);  
}

void loop()
{
 deger=digitalRead(pir);
 
  Serial.println(deger);
  
  if(deger==HIGH){
  digitalWrite(dc1, HIGH);
  delay(1000);
  }
  else{
  digitalWrite(dc2, LOW);
  digitalWrite(dc1, LOW);
  delay(1000);
  }
}

//Engelden kaçan robot
int sol_g=2;
int sol_i=3;
int sag_g=9;
int sag_i=10;
int trigPin=11;
int echoPin=12;
float sure;
long mesafe;

void setup()
{
  pinMode(sol_g, OUTPUT);
  pinMode(sol_i, OUTPUT);
  pinMode(sag_g, OUTPUT);
  pinMode(sag_i, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  sure=pulseIn(echoPin,HIGH);
  mesafe=(sure*0.034)/2;
  
  Serial.println(mesafe);
  
  
  if(mesafe<40){
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,HIGH);
  digitalWrite(sag_i,LOW);
  digitalWrite(sag_g,HIGH);
    
  delay(1500);
    
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,HIGH);
  digitalWrite(sag_i,HIGH);
  digitalWrite(sag_g,LOW);
    
  delay(2500);
  }
  
  else{
  digitalWrite(sol_i,LOW);
  digitalWrite(sol_g,HIGH);
  digitalWrite(sag_i,LOW);
  digitalWrite(sag_g,HIGH);
  }
}








