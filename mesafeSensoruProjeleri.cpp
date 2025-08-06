//Hırsız alarmı
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
//Arsaç park sensörü
int trigPin=8;
int echoPin=9;
int kirmizi=10;
int mavi=11;
int yesil=12;
int buzzer=13;
long sure;
float mesafe;

void setup()
{
  pinMode(trigPin,OUTPUT);//Trig çıkış
  pinMode(echoPin,INPUT);//Echo giriş
  pinMode(kirmizi,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(buzzer,OUTPUT);//Buzzer ses çıkış
  Serial.begin(9600);
}

void loop()
{
  //Sensörün hazır hale gelmesini sağlamak için
  digitalWrte(trigPin,LOW);
  delayMicroseconds(2);
  
  //Trig pine 10 mikro saniyelik bir HIGH (açık) sinyal gönderilir
  //Bu, sensörün ultrasonik ses dalgası göndermesini sağlar
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  sure=pulseIn(echoPin,HIGH);//Echo süresini oku
  mesafe=(sure*0.034)/2;//cm cinsinden hesapla
  Serial.println(mesafe);//mesafeyi yazdır

  //mesafe 10 cm den küçük ise tüm lambalar yansın ve buzzer sürekli ses çıkarsın
  if(mesafe<10){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(mavi,HIGH);
  digitalWrite(yesil,HIGH);
    tone(buzzer,1000);
  }
  //mesafe 10cm ile 30cm arasında ise yeşil ve mavi lambalar yansın ve buzzer 0.5 saniyede bir ses çıkarsın
  else if(mesafe>10 && mesafe<30){
  digitalWrite(kirmizi,LOW);
  digitalWrite(mavi,HIGH);
  digitalWrite(yesil,HIGH);
  tone(buzzer,1000);
  delay(500);
  noTone(buzzer);  
  delay(500);
  }
  //mesafe 30cm ile 50cm arasında ise sadece yeşil lamba yansın ve buzzer 1 saniyede bir ses çıkarsın
  else if(mesafe>30 && mesafe<50){
  digitalWrite(kirmizi,LOW);
  digitalWrite(mavi,LOW);
  digitalWrite(yesil,HIGH);
  tone(buzzer,1000);
  delay(1000);
  noTone(buzzer);  
  delay(1000);
  }
    //mesafe 50cm den büyük ise tüm lambalar sönsün ve buzzer sussun
  else{
  digitalWrite(kirmizi,LOW);
  digitalWrite(mavi,LOW);
  digitalWrite(yesil,LOW);
  noTone(buzzer);  
  }
}
//Mesafe Sensörü İle Led Yakma 
int kirmizi=5;
int yesil=6;
int mavi=7;
int trigPin=8;
int echoPin=13;

void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  long sure;
  float mesafe;
  
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
  
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
  
 digitalWrite(trigPin,LOW);

  sure=pulseIn(echoPin,HIGH);
  mesafe=(sure/2)/29.1;
  
  Serial.println(mesafe);
  
  if(mesafe<30){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(yesil,HIGH);
  digitalWrite(mavi,HIGH);
  }
  else if(mesafe>30 && mesafe<70){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(yesil,HIGH);
  digitalWrite(mavi,LOW);
  }
  if(mesafe>70 && mesafe<100){
  digitalWrite(kirmizi,HIGH);
  digitalWrite(yesil,LOW);
  digitalWrite(mavi,LOW);
  }
  else{
  digitalWrite(kirmizi,LOW);
  digitalWrite(yesil,LOW);
  digitalWrite(mavi,LOW);
  }
}


























