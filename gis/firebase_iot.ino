/* 
    WEB GIS REALTIME + IOT + FIREBASE
    ---------------------------------
    Sebelum menggunakan kode ini, pastikan Anda telah mengikuti langkah-langkah berikut.

    1.  Buka Sketch > Include Library > Manage Libraries...
        Kemudian cari dan install library di bawah ini. Jika library tidak ada pada pencarian,
        Anda bisa download dari link Github.
        - Firebase Arduino Client Library for ESP8266 and ESP32 (v2.6.6)
        https://github.com/mobizt/Firebase-ESP-Client
        - TinyGPSPLUS (v1.0.2)
        https://github.com/Tinyu-Zhao/TinyGPSPlus
        - DHT sensor library (v1.4.3)
        https://github.com/adafruit/DHT-sensor-library

    2.  Buka File > Preferences
        Kemudian tambahkan URL berikut ke kolom Additional Boards Manager URLs.
        https://arduino.esp8266.com/stable/package_esp8266com_index.json

    3.  Buka Tools > Boards > Board Manager, kemudian cari esp8266 dan install board esp8266 (v3.0.2).

    4.  Buka dan pilih Tools > MMU > 16KB cache + 48KB IRAM and 2nd Heap (shared)

    Selesai!!!
    ----------
*/

// include header dan library
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/RTDBHelper.h>
#include <TinyGPSPlus.h>
#include <DHT.h>

// konstanta untuk mengatur koneksi, ubah sesuai kebutuhan
#define WIFI_SSID           F("NAMA SSID WIFI")
#define WIFI_PASSWORD       F("PASSWORD WIFI")
#define GPS_PIN_RX          D1
#define GPS_PIN_TX          D2
#define DHT_PIN             D3
#define DHT_TYPE            DHT22
#define FIREBASE_HOST       "xxxx.firebaseio.com"  // Firebase > Realtime Database
#define FIREBASE_SECRET     "xxxx"                 // Firebase > Project Settings > Service accounts > Database secrets
#define LOCATION_NAME       F("Leuwiliang")

// objek library GPS, DHT, dan Firebase
TinyGPSPlus gps;
SoftwareSerial gps_serial(GPS_PIN_RX, GPS_PIN_TX);
DHT dht(DHT_PIN, DHT_TYPE);

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// kode ini dieksekusi sekali saat ESP8266 diinisialisasi
void setup() 
{
    // mulai koneksi ke DHT, Serial (komputer), GPS, dan Wifi
    dht.begin();
    Serial.begin(9600);
    gps_serial.begin(9600);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    // menunggu wifi terhubung
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi tersambung!");
    Serial.println("Server aktif!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    // mengatur koneksi ke Firebase
    config.database_url = FIREBASE_HOST;
    config.signer.tokens.legacy_token = FIREBASE_SECRET;

    Firebase.reconnectWiFi(true);
    Firebase.begin(&config, &auth);
}

// kode ini dieksekusi sekali setiap dua detik
void loop()
{
    // variabel untuk menampung data dari GPS dan DHT
    float latitude = 0, longitude = 0, rh = 0, temp = 0;

    // cek apakah ada data dari GPS
    while (gps_serial.available() > 0)
    {
        // cek apakah lokasi sudah ditemukan
        if (!gps.encode(gps_serial.read())) continue;
        if (!gps.location.isValid()) continue;

        // mengambil koordinat
        latitude = gps.location.lat();
        longitude = gps.location.lng();

        // menampilkan koordinat ke Serial (komputer)
        Serial.print("Latitude: ");
        Serial.print(latitude);
        Serial.print(", Longitude: ");
        Serial.print(longitude);
    }

    // mengambil kelembapan udara dan suhu
    rh = dht.readHumidity();
    temp = dht.readTemperature();

    // kirim data ke Firebase, ubah angka pada /1/ menjadi nomor kelompok kamu!
    Firebase.RTDB.setString(&fbdo, "/DHT11/1/lokasi", LOCATION_NAME);
    Firebase.RTDB.setFloat(&fbdo, "/DHT11/1/lat", latitude);
    Firebase.RTDB.setFloat(&fbdo, "/DHT11/1/long", longitude);
    Firebase.RTDB.setFloat(&fbdo, "/DHT11/1/rh", rh);
    Firebase.RTDB.setFloat(&fbdo, "/DHT11/1/temp", temp);

    // tampilkan suhu dan kelembapan udara ke Serial (komputer)
    Serial.print(F("Kelembaban udara: "));
    Serial.print(rh);
    Serial.println(F("%"));

    Serial.print(F("Suhu udara: "));
    Serial.print(temp);
    Serial.println(F(" *C"));

    // tunggu 2 detik sebelum mengulangi proses
    delay(2000);
}
