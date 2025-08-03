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

//LDR Sensör İle 5 Led'i Sırayla Yakma
int led1=5;
int led2=6;
int led3=7;
int led4=8;
int led5=9;
int ldr=A0;
int ldrDeger;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  ldrDeger=analogRead(ldr);
  Serial.println(ldrDeger);
  
  if(ldrDeger<1020 && ldrDeger>882){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
    delay(300);
  } 
  if(ldrDeger<882 && ldrDeger>748){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
    delay(300);
  } 
  if(ldrDeger<748 && ldrDeger>613){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
    delay(300);
  } 
  if(ldrDeger<613 && ldrDeger>479){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,LOW);
    delay(300);
  } 
  if(ldrDeger<479 && ldrDeger>344){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
    delay(300);
  }  
}

//LDR Sensör İle Karanlıkta RGB Led Yakma
int kirmizi=5;
int mavi=6;
int yesil=7;
int ldr=A0;
int ldrdeger;

void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop()
{
  ldrdeger=analogRead(ldr);
  Serial.println(ldrdeger);
  
  if(ldrdeger<1000 && ldrdeger>800){
  analogWrite(kirmizi,255);
  analogWrite(mavi,255);
  analogWrite(yesil,255);
  }
  if(ldrdeger<800 && ldrdeger>600){
  analogWrite(kirmizi,100);
  analogWrite(mavi,100);
  analogWrite(yesil,100);
  }
  if(ldrdeger<600 && ldrdeger>400){
  analogWrite(kirmizi,100);
  analogWrite(mavi,200);
  analogWrite(yesil,50);
  }
 
}
























