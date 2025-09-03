// Kızılötesi Kumanda ile LED Kontrolü
#include <IRremote.h>  // IR kumanda ile haberleşme için gerekli kütüphane

// Uzaktan kumandadaki tuşların HEX kodları
#define buton0  0xF30CBF00  // LED kapatma
#define buton1  0xEF10BF00  // LED açma

#define kizilotesi 2 // IR alıcının bağlı olduğu Arduino pini
int led = 5;  // LED'in bağlı olduğu Arduino pini

void setup() {
  pinMode(led, OUTPUT); 
  Serial.begin(9600); 
  IrReceiver.begin(kizilotesi, ENABLE_LED_FEEDBACK); // IR alıcıyı başlat ve LED geri bildirimini etkinleştir
}

void loop() {
  // Eğer IR kumandadan bir sinyal gelirse
  if (IrReceiver.decode()) {
     unsigned long deger = IrReceiver.decodedIRData.decodedRawData; // Gelen kodu al

    // Gelen kodu kontrol et ve LED'i aç/kapat
    if (deger == buton1) {
      digitalWrite(led, HIGH);
      Serial.println("LED Açık");
    }
    else if (deger == buton0) {
      digitalWrite(led, LOW);
      Serial.println("LED Kapalı");
    }

    IrReceiver.resume(); // Bir sonraki IR sinyalini almak için alıcıyı hazırla
  }
}

//Kumanda ile RGB Led Yakma
#include <IRremote.h>

#define kizilotesi 2
#define buton1 0xEF10BF00
#define buton2 0xEE11BF00
#define buton3 0xED12BF00
#define guc    0xFF00BF00

int kirmizi = 3;
int mavi    = 4;
int yesil   = 5;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(yesil, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(kizilotesi, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long deger = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(deger, HEX); // gelen kodu görmek için

    if (deger == buton1) {
      digitalWrite(kirmizi, HIGH);
      digitalWrite(mavi, LOW);
      digitalWrite(yesil, LOW);
    }
    else if (deger == buton2) {
      digitalWrite(kirmizi, LOW);
      digitalWrite(mavi, HIGH);
      digitalWrite(yesil, LOW);
    }
    else if (deger == buton3) {
      digitalWrite(kirmizi, LOW);
      digitalWrite(mavi, LOW);
      digitalWrite(yesil, HIGH);
    }
    else if (deger == guc) {
      digitalWrite(kirmizi, LOW);
      digitalWrite(mavi, LOW);
      digitalWrite(yesil, LOW);
    }

    IrReceiver.resume(); 
  }
}

// Kumanda ile Dc Motor Kontrolü
#include<IRremote.h>
#define kizilotesi 6
#define dc1 2
#define dc2 3
# define sag 0xFB04BF00
#define sol 0xF906BF00
#define guc 0xFF00BF00


void setup()
{
  pinMode(dc1, OUTPUT);
  pinMode(dc2, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(kizilotesi, ENABLE_LED_FEEDBACK);
}

void loop()
{
  if (IrReceiver.decode()) {
    unsigned long deger = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(deger, HEX);
    
    if(deger==sag){
    digitalWrite(dc1,HIGH);
    digitalWrite(dc2,LOW);
    }
    else if(deger==sol){
    digitalWrite(dc1,LOW);
    digitalWrite(dc2,HIGH);
    }
    else if(deger==guc){
    digitalWrite(dc1,LOW);
    digitalWrite(dc2,LOW);
    }
    IrReceiver.resume();
  }    
}

// Kumanda ile Araba Kontrolü
#include<IRremote.h>
#define kizilotesi 8
#define sag_g 2
#define sag_i 3
#define sol_g 6
#define sol_i 7
#define ileri 0xFB04BF00
#define geri 0xF906BF00
#define guc 0xFF00BF00

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(kizilotesi, ENABLE_LED_FEEDBACK);
}

void loop()
{
  if (IrReceiver.decode()) {
    unsigned long deger = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(deger, HEX);
    
    if(deger==ileri){
    digitalWrite(sag_g,HIGH);
    digitalWrite(sag_i,LOW);
    digitalWrite(sol_g,HIGH);
    digitalWrite(sol_i,LOW);
    }
    else if(deger==geri){
    digitalWrite(sag_g,LOW);
    digitalWrite(sag_i,HIGH);
    digitalWrite(sol_g,LOW);
    digitalWrite(sol_i,HIGH);
    }
    else if(deger==guc){
    digitalWrite(sag_g,LOW);
    digitalWrite(sag_i,LOW);
    digitalWrite(sol_g,LOW);
    digitalWrite(sol_i,LOW);
    }
    IrReceiver.resume();
  }    
}

//Kumanda ile Kapı Açıp Kapama
#include<Servo.h>
#include<IRremote.h>

#define kizilotesi 2
#define guc 0xFF00BF00// Kumandadaki güç tuşu kodu (Serial Monitor'dan kontrol et!)

int sayac=0;//0=kapalı,1=açık
Servo motor;

void setup() {
  motor.attach(5);// Servo sinyal pini Arduino'nun D5 pinine bağlı
  Serial.begin(9600);
  IrReceiver.begin(kizilotesi, ENABLE_LED_FEEDBACK);
  motor.write(0);
}

void loop() {
 
  if(IrReceiver.decode()){
    unsigned long kod=IrReceiver.decodedIRData.decodedRawData;
    Serial.println(kod, HEX);

    if(kod==guc && sayac==0){
      motor.write(180);// Kapak açılsın
      sayac=1;
    }
    else if(kod==guc && sayac==1){
      motor.write(0);// Kapak kapansın
      sayac = 0;
    }
    delay(300);// Tek tuş basışını birden fazla algılamasın diye
    IrReceiver.resume();
  }
}




























