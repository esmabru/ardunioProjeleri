//LDR ile led yakma 
int ldr=A0;
int ldr_deger;
int led=7;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop()
{
 ldr_deger=analogRead(ldr);
  Serial.println(ldr_deger);
  if(ldr_deger>800){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
//Ldr Sensör ile Karanlığa Doğru Led'in Artarak Yanması
int led=5;
int ldr=A0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(ldr));
  //2 ye bölme sebebimiz analog değerin 0-1023 arası bir değer okuyacak olması biz bu değeri daha da minimuma indiriyoruz çünkü analog write 0-255 arasını kabul eder
  analogWrite(led,analogRead(ldr)/2);
  delay(10);
}
