/* 
    WEB GIS REALTIME + IOT + FIREBASE
    ---------------------------------
    Sebelum menggunakan kode ini, pastikan Anda telah mengikuti langkah-langkah berikut.

    1.  Buka File > Preferences
        Kemudian tambahkan URL berikut ke kolom Additional Boards Manager URLs.
        https://arduino.esp8266.com/stable/package_esp8266com_index.json

        Buka Tools > Boards > Board Manager, kemudian cari ESP8266 Module 2.7.4 - NodeMCU 0.9.

    2.  Buka Sketch > Include Library > Manage Libraries...
        Kemudian cari dan install library di bawah ini. 
        - DHT_sensor_library
        - ArduinoJson 5.13.5
        - NTPClient 3.2.0
        
        Jika library tidak ada pada pencarian,
        Anda bisa download dari link Github.
        - FirebaseArduino
        https://github.com/FirebaseExtended/firebase-arduino
        - TinyGPS++
         https://github.com/mikalhart/TinyGPSPlus/releases
        
    3.  Driver USB to NodeMCU
        - CH341 : http://www.wch-ic.com/downloads/CH341SER_EXE.html atau 
        - CP210 : https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers

    Selesai!!!
    ----------
*/


//GPS
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
int RXPin = D2;
int TXPin = D3;
SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSPlus gps;
float latitude, longitude;
String lat_str, lng_str;

//WIFI
#include <ESP8266WiFi.h>
#define WIFI_SSID "LABKOM" // ganti dan sesuaikan dengan nama wifi
#define WIFI_PASSWORD "maroon2018" // ganti dan sesuaikan dengan password wifi

//FIREBASE
#include <FirebaseArduino.h>
#define FIREBASE_HOST "praktikumsig-2b4b1-default-rtdb.asia-southeast1.firebasedatabase.app" // ganti dan sesuaikan dengan firebase
#define FIREBASE_AUTH "JUug0cVkgi3uav97fPZd3FKnIr9RBrIlABddj9ZN" // ganti dengan key firebase

//DHT11
#include <DHT.h>
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int suhu, kelembaban;

//TIME
#include <NTPClient.h>
#include <WiFiUdp.h>
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 25200);
String nama_hari[7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
String nama_bulan[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

void setup() {
  Serial.begin(9600);

  //DHT11
  dht.begin(9600);
  //sensor
  gpsSerial.begin(9600);

  //WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Sedang Mengubungkan");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Terhubung dengan Jaringan ");
  Serial.println(WiFi.localIP());

  //Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  

  Firebase.setString("Asprak/nama", "Ruang Asprak GIS"); // Ganti sesuai dengan urutan kelompok contoh "Kelompok 1"
}

void loop()
{
  float kelembaban = dht.readHumidity();
  float suhu = dht.readTemperature();
  timeClient.update();

  unsigned long waktu_epoch = timeClient.getEpochTime();
  String jam = timeClient.getFormattedTime();
  String hari = nama_hari[timeClient.getDay()];
  struct tm *ptm = gmtime ((time_t *)&waktu_epoch);
  int tanggal = ptm->tm_mday;
  String bulan = nama_bulan[ptm->tm_mon];;
  int tahun = ptm->tm_year + 1900;
  String waktu_terkini = hari + ", " + String(tanggal) + " " + bulan + " " + String(tahun) + " " + jam;

  if (isnan(kelembaban) || isnan(suhu)) {
    Serial.println(F("Gagal membaca DHT sensor!"));
    return;
  }

  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        latitude = gps.location.lat();
        lat_str = String(latitude , 10);
        longitude = gps.location.lng();
        lng_str = String(longitude , 10);
      }
      Firebase.setString("Asprak/latitude", lat_str);
      Firebase.setString("Asprak/longitude", lng_str);
    }
  }

  Serial.print(F("Latitude : "));
  Serial.print(latitude);
  Serial.print(F(" Longitude: "));
  Serial.print(longitude);
  Serial.print("\n");
  Serial.print(F("Kelembapan : "));
  Serial.print(kelembaban);
  Serial.print(F(" Suhu: "));
  Serial.print(suhu);
  Serial.print(F(" °C"));
  Serial.print("\n");
  Serial.print("Terakhir Diperbarui: ");
  Serial.println(waktu_terkini);
  Serial.println("");


  if (Firebase.failed()) {
    Serial.print("Gagal mendapatkan firebase");
    Serial.println(Firebase.error());
    return;
  }

  Firebase.setFloat("Asprak/suhu", suhu);
  Firebase.setFloat("Asprak/kelembaban", kelembaban);
  Firebase.setString("Asprak/diperbaharui", waktu_terkini);



  delay(2000);
}