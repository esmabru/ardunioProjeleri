//Led yakma kodu
int led=5;
void setup(){
  pinMode(led,OUTPUT);
}
void loop(){
  digitalWrite(led,HIGH);//Açma kodu
  delay(1000);
  digitalWrite(led,LOW);//Kapama kodu
  delay(1000);}

//Ledin parlaklığını ayarlama kodu
int led=5;

void setup(){
  pinMode(led,OUTPUT);
}

void loop(){
  // Parlaklığı 0'dan 255'e artır
  for(int i=0;i<=255;i++) {
    analogWrite(led,i);
    delay(10);
  }
  // Parlaklığı 255'ten 0'a azalt
  for(int i=255;i>=0;i--) {
    analogWrite(led,i);
    delay(10);
  }
}
