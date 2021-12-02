//GPS
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
int RXPin = D2;
int TXPin = D3;
SoftwareSerial gpsSerial(RXPin, TXPin);
TinyGPSPlus gps;
int latitude, longitude;
String lat_str, lng_str;

//WIFI
#include <ESP8266WiFi.h>
#define WIFI_SSID "DESKTOP-6IDBF47"
#define WIFI_PASSWORD "12345678"

//FIREBASE
#include <FirebaseArduino.h>
#define FIREBASE_HOST "gisiot-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "o1sAR4U9cId9QRnF3vdCctICQhs8AVQQr5bS0Pew"

//DHT11
#include "DHT.h"
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
        Firebase.setString("kelompok2/latitude", lat_str);
        Firebase.setString("kelompok2/longitude", lng_str);
      }
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
    Serial.print("Gagal mengupdate data suhu");
    Serial.println(Firebase.error());
    return;
  }

  Firebase.setFloat("GIS/kelompok2/suhu", suhu);
  Firebase.setFloat("GIS/kelompok2/kelembaban", kelembaban);
  Firebase.setString("GIS/kelompok2/diperbaharui", waktu_terkini);



  delay(2000);
}
