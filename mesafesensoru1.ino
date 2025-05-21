int trigPin=9;
int echoPin=10;
int buzzerPin=13;

void setup(){
  pinMode(trigPin,OUTPUT);//Trig çıkış
  pinMode(echoPin,INPUT);//Echo giriş
  pinMode(buzzerPin,OUTPUT);//Buzzer ses çıkış
}

void loop(){
  long sure;
  float mesafe;

  //Sensörün hazır hale gelmesini sağlamak için
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  //Trig pine 10 mikro saniyelik bir HIGH (açık) sinyal gönderilir
  //Bu, sensörün ultrasonik ses dalgası göndermesini sağlar
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  //Echo süresini oku
  sure=pulseIn(echoPin,HIGH);
  mesafe=(sure*0.034)/2;//cm cinsinden hesapla

  if(mesafe<10 && mesafe>0){
    tone(buzzerPin,1000);
  }
  else if(mesafe<30){
    tone(buzzerPin,1000);
    delay(300);
    noTone(buzzerPin);
    delay(300);
  }  
  else if(mesafe<50){
    tone(buzzerPin,1000);
    delay(500);
    noTone(buzzerPin);
    delay(500);
  }  
 
  else 
  noTone(buzzerPin);

}