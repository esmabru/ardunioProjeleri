# Arduino ile Temel Elektronik Projesi – Tinkercad Simülasyonu

Bu proje, **Arduino platformunu kullanarak temel elektronik uygulamaları öğrenmek ve simüle etmek** amacıyla hazırlanmıştır. LED kontrolü, servo motor hareketi, mesafe sensörü ile ölçüm, alarm sistemleri ve çeşitli diğer sensörlerle etkileşim gibi temel işlemleri içermektedir. Proje hem fiziksel olarak Arduino üzerinde çalıştırılabilir, hem de Tinkercad ortamında simüle edilebilir.

---

## 🔧 İçerik

Projede yer alan temel uygulamalar:

- 🔴 **LED Yakma ve Yanıp Sönme**
- 🔁 **Servo Motor Kontrolü**
- 📏 **Ultrasonik Sensör ile Mesafe Ölçümü**
- 🚨 **Basit Alarm Sistemi**
- 🌡️ **Sıcaklık ve Işık Sensörü ile Veri Okuma**

---

## 🚀 Başlangıç

Bu projeyi çalıştırmak için aşağıdaki adımları izleyin.

### 📋 Gereksinimler

- Arduino Uno (veya uyumlu başka bir Arduino modeli)  
- Arduino IDE
- Tinkercad Hesabı
- USB kablosu  
- Gerekli elektronik bileşenler (LED, direnç, sensörler, servo motor vb.)

---

## 🔌 Kurulum

1. Arduino IDE'yi bilgisayarınıza kurun.
2. Bu projeye ait Arduino kodlarını indirin veya Tinkercad üzerinde kendinize ait bir kopyasını oluşturun.
3. Arduino'yu bilgisayara bağlayın.
4. Arduino IDE'de **Araçlar > Kart > Arduino Uno** seçimini yapın.
5. **Port** seçimini doğru yaptığınızdan emin olun (örneğin: COM3).
6. Kodu Arduino'ya yüklemek için **"Yükle"** butonuna tıklayın.

---

## ⚙️ Donanım Kurulumu

### Arduino Bağlantısı

- Arduino’nuzu bilgisayara USB ile bağlayın.
- IDE üzerinden doğru kart ve portu seçin.

### Sensör Bağlantısı (Örnek: HC-SR04 Ultrasonik Sensör)

- **VCC → 5V**  
- **GND → GND**  
- **Trig → D9**, **Echo → D10** (örnek pinler)

### LED Bağlantısı

- **Uzun bacak (anot) → D13**  
- **Kısa bacak (katot) → GND (220Ω direnç üzerinden)**

### Servo Motor Bağlantısı

- **Kırmızı kablo (VCC) → 5V**
- **Kahverengi/Siyah kablo (GND) → GND**
- **Sinyal kablosu → D3** (örnek)

---

## 💡 Simülasyon (Tinkercad)

Tinkercad üzerinden çalıştırmak için:

1. [Tinkercad](https://www.tinkercad.com/) sitesine giriş yapın.
2. "Devreler" sekmesinden yeni bir proje oluşturun.
3. Arduino ve diğer bileşenleri ekleyip bağlantıları yapın.
4. Kod editöründe Arduino kodlarını yazın veya yapıştırın.
5. "Başlat" butonuna tıklayarak simülasyonu çalıştırın.

---

## 📌 Proje Özellikleri

- Tüm modüller tek tek veya birlikte çalıştırılabilir.
- Tinkercad ile sanal ortamda test edilebilir.
- Başlangıç düzeyindeki kullanıcılar için uygundur.
- Gerçek donanım kullanılarak fiziksel test imkânı sunar.
- Temel elektronik ve Arduino mantığını öğretici yapıda.

