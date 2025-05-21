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
