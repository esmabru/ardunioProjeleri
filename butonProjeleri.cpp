//Buton ile led yakma
int led=8;
int button=5;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop(){
  if(digitalRead(button)==HIGH){ 
    digitalWrite(led,HIGH);
  }
  if(digitalRead(button)==HIGH){
    digitalWrite(led,LOW);
  }
}
//Buton ile ledi açma kapama
int leddurum=0;
int butondurum=0;
int x=0;
void setup()
{
  pinMode(8,OUTPUT);
  pinMode(5,INPUT);
}

void loop()
{
  butondurum=digitalRead(5);/*Bunu okuyor ve basılırsa 1 değerini
  basılmazsa 0 değerini atıyor*/
    if(butondurum==1 && x==0){
    x=1;
      if(leddurum==0)
      leddurum=1;
      else
      leddurum=0;
  }
  if(leddurum==1)
    digitalWrite(8,HIGH);
  else
    digitalWrite(8,LOW);
  if(butondurum==0 &&x==1){
    x=0;
  }
  delay(10);
}
//Buton ile kontrol edilen trafik lambası
int arack=6;
int aracs=7;
int aracy=8;
int yayak=9;
int yayay=10;
int buton=5;
int butondurum=0;
void setup()
{
  pinMode(arack,OUTPUT);
  pinMode(aracs,OUTPUT);
  pinMode(aracy,OUTPUT);
  pinMode(yayak,OUTPUT);
  pinMode(yayay,OUTPUT);
  pinMode(buton,INPUT);
}

void loop()
{
  butondurum=digitalRead(buton);
  if(butondurum==HIGH){
    digitalWrite(arack,LOW);
    digitalWrite(aracs,LOW);
    digitalWrite(aracy,HIGH);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
    delay(1000);
    
    digitalWrite(arack,LOW);
    digitalWrite(aracs,HIGH);
    digitalWrite(aracy,LOW);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
    delay(2000);
    
    digitalWrite(arack,HIGH);
    digitalWrite(aracs,LOW);
    digitalWrite(aracy,LOW);
    digitalWrite(yayak,LOW);
    digitalWrite(yayay,HIGH);
    delay(10000);
    
    digitalWrite(arack,LOW);
    digitalWrite(aracs,HIGH);
    digitalWrite(aracy,LOW);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
    delay(1000);
  }
  else{
    digitalWrite(arack,LOW);
    digitalWrite(aracs,LOW);
    digitalWrite(aracy,HIGH);
    digitalWrite(yayak,HIGH);
    digitalWrite(yayay,LOW);
  }
}
//3 Butonla 1 Led'i Farklı Şekilde Yakma
int led=5;
int deger=0;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  deger=analogRead(A0);
  Serial.println(deger);
  
  if(deger<1024 && deger>1000){
  digitalWrite(led,HIGH);
  delay(10000);
  digitalWrite(led,LOW); 
  delay(10000);  
  }
  if(deger<700 && deger>400){
  digitalWrite(led,HIGH);
  delay(3000);
  digitalWrite(led,LOW); 
  delay(3000);
  }
  if(deger<350 && deger>0){
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW); 
  delay(1000);  
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW); 
  delay(1000); }
}
//2 Buton İle 3 Led'i Farklı Şekilde Yakma
int button1=2;
int button2=3;
int kirmizi=4;
int yesil=5;
int mavi=6;
int t=900;// LED’ler arası kayma süresi
int sayac=0;

void setup() {
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
}

void sola(){
  digitalWrite(mavi,1);
  digitalWrite(yesil,0);
  digitalWrite(kirmizi,0);
  delay(t);     
  digitalWrite(mavi,0);
  digitalWrite(yesil,1);
  digitalWrite(kirmizi,0);
  delay(t);  
  digitalWrite(mavi,0);
  digitalWrite(yesil,0);
  digitalWrite(kirmizi,1);
  delay(t);
}

void saga() {
  digitalWrite(mavi,0);
  digitalWrite(yesil,0);
  digitalWrite(kirmizi,1);
  delay(t);     
  digitalWrite(mavi,0);
  digitalWrite(yesil,1);
  digitalWrite(kirmizi,0);
  delay(t);  
  digitalWrite(mavi,1);
  digitalWrite(yesil,0);
  digitalWrite(kirmizi,0);
  delay(t);    
}

void flash() {
  digitalWrite(mavi,0);
  digitalWrite(yesil,0);
  digitalWrite(kirmizi,0);
  delay(t);     
  digitalWrite(mavi,1);
  digitalWrite(yesil,1);
  digitalWrite(kirmizi,1);
  delay(t);      
}

void loop() {
  if(digitalRead(button1)== 1){ // Buton1’e basılırsa sola
    sayac=1;
  }
  else if(digitalRead(button2) == 1) { // Buton2’ye basılırsa sağa
    sayac = 2;
  }
  else{ // Hiçbiri basılmıyorsa flash
    sayac = 3;
  }

  if(sayac == 1) sola();
  else if(sayac == 2) saga();
  else if (sayac == 3) flash();
}
//1 Butona Her Bastığımızda 3 Led'i Farklı Şekilde Yakma
int kirmizi=3;
int yesil=4;
int mavi=6;
int buton=5;
int butonDurum=0;
int deger=0;

void setup()
{
  pinMode(kirmizi,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(mavi,OUTPUT);
  pinMode(buton,INPUT);
}

void loop()
{
  butonDurum=digitalRead(buton);
  
  if(butonDurum==HIGH && deger==0){
    digitalWrite(kirmizi, HIGH);
    digitalWrite(yesil, LOW);
    digitalWrite(mavi, LOW);
    deger=1;
    delay(10);
  }
  if(butonDurum==LOW && deger==1){
    deger=2;
    delay(10);
  }
  if(butonDurum==HIGH && deger==2){
    digitalWrite(kirmizi, HIGH);
    digitalWrite(yesil, HIGH);
    digitalWrite(mavi, LOW);
    deger=3;
    delay(10);
  }
 if(butonDurum==LOW && deger==3){
    deger=4;
    delay(10);
  } 
if(butonDurum==HIGH && deger==4){
    digitalWrite(kirmizi, HIGH);
    digitalWrite(yesil, HIGH);
    digitalWrite(mavi, HIGH);
    deger=5;
    delay(10);
  }  
if(butonDurum==LOW && deger==5){
    deger=6;
    delay(10);
  } 
 if(butonDurum==HIGH && deger==6){
    digitalWrite(kirmizi, LOW);
    digitalWrite(yesil, LOW);
    digitalWrite(mavi, LOW);
    deger=7;
    delay(10);
  }   
if(butonDurum==LOW && deger==7){
    deger=0;
    delay(10);
  }   
}
// 1 Buton İle Zaman Ayarlı Led Yakma
int kirmizi=5;
int yesil=6;
int mavi=7;
int buton=8;
int deger=0;
int say=0;
bool islem=false;

void setup()
{
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(buton, INPUT);
  Serial.begin(9600);
}

void loop()
{
deger=digitalRead(buton);//dijital okuma yapıyor
Serial.println(deger);
  
  while(deger==1){
  delay(100);
  say++;
  deger=digitalRead(buton);/*butonu tekrar okuyoruz ki,while 
  takılı kalmasın aksi halde deger değişkeni hep 1 olduğu için 
  while sonsuz döngüye girer*/
  islem=true;
  }
  Serial.println(say);
  if(islem==true){
  
    if(say>0 && say<=10){//1 saniye basıldı
      digitalWrite(kirmizi,HIGH);
      digitalWrite(yesil,LOW);
      digitalWrite(mavi,LOW);
  }
   else if (say>10 && say<=30){//2 saniye basıldı
      digitalWrite(kirmizi,LOW);
      digitalWrite(yesil,HIGH);
      digitalWrite(mavi,LOW);
  }
    else//2 saniyeden fazla basıldı
    {
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(mavi,HIGH);
    }
    say=0;
    islem=false;
  }
}



 


