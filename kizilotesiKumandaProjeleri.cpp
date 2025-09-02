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

  
   
