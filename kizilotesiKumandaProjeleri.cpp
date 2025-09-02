// Kızılötesi Kumanda ile LED Kontrolü
#include <IRremote.h>  // IR kumanda ile haberleşme için gerekli kütüphane

// Uzaktan kumandadaki tuşların HEX kodları
#define BUTTON_OFF  0xF30CBF00  // LED kapatma tuşu
#define BUTTON_ON   0xEF10BF00  // LED açma tuşu

#define IR_PIN 2   // IR alıcının bağlı olduğu Arduino pini
int ledPin = 5;  // LED'in bağlı olduğu Arduino pini

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK); // IR alıcıyı başlat ve LED geri bildirimini etkinleştir
}

void loop() {
  // Eğer IR kumandadan bir sinyal gelirse
  if (IrReceiver.decode()) {
    unsigned long receivedCode = IrReceiver.decodedIRData.decodedRawData; // Gelen kodu al

    // Gelen kodu kontrol et ve LED'i aç/kapat
    if (receivedCode == BUTTON_ON) {
      digitalWrite(ledPin, HIGH); 
      Serial.println("LED Açık");
    }
    else if (receivedCode == BUTTON_OFF) {
      digitalWrite(ledPin, LOW);
      Serial.println("LED Kapalı");
    }

    IrReceiver.resume(); // Bir sonraki IR sinyalini almak için alıcıyı hazırla
  }
}
