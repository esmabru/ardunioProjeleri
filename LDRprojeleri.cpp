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
