#include <WiFi.h>
#include "ThingSpeak.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
#include <TinyGPS++.h>

#define DHTPIN 4        // Pin ESP yang tersambung ke pin Data DHT22 (pin 2)
#define DHTTYPE DHT22   // jenis sensor DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

float hum = 0;		//variabel untuk menyimpan nilai kelembaban
float temp = 0; 	// variabel untuk menyimpan nilai suhu
float hic = 0; 		// heat index dalam celcius

TinyGPSPlus gps;  	// the TinyGPS++ object
String lat_data, lng_data;
#define GPS_BAUDRATE 9600


char ssid[] = "Wokwi-GUEST";	// Wokwi Wifi
char pass[] = "";   		//Blank Password
int keyIndex = 0;            	// your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = XXXXXXX;
const char * myWriteAPIKey = "XXXXXXXXXXXXXXXX";

unsigned long previousMillis_ts = 0;
unsigned long previousMillis_display = 0;

const long ts_update_interval = 20000;  //update data setiap 10s
const long display_interval = 1000;

void setup() {
  Serial.begin(9600);
  Serial0.begin(GPS_BAUDRATE);		//serial2 for GPS UART
  Serial.println(F("Temp & Humid Monitoring System"));
  dht.begin();

  delay(3000);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);  		// Initialize ThingSpeak
  ConnectWIFI();
}

void loop() {
  if (Serial0.available() > 0) {
    if (gps.encode(Serial0.read())) {
      if (gps.location.isValid()) {
        Serial.println(F("======================")); 
        Serial.print(F("Lat: ")); Serial.print(gps.location.lat(), 6);
        lat_data = String(gps.location.lat(), 8);

        Serial.print(F(" , Longitude: ")); Serial.println(gps.location.lng(), 6);
        lng_data = String(gps.location.lng(), 8);

      } else {
        Serial.println(F("Location: INVALID"));
      }
      //Serial.println();
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) {
   Serial.println(F("No GPS data received: check wiring")); 
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis_display >= display_interval) {
    previousMillis_display = currentMillis;

    hum = dht.readHumidity();
    temp = dht.readTemperature(); // membaca suhu dalam Celsius

    // temp = dht.readTemperature(true);  //suhu dalam Fahrenheit

    // Check if any reads failed and exit early (to try again).
    if (isnan(hum) || isnan(temp)) {
      Serial.println(F("Gagal mendapat data dari sensor DHT!"));
      return;
    }
    Serial.print(F("Temperature: ")); 
    Serial.print(temp);
    Serial.print(", ");
    Serial.print(F("Humidity: ")); 
    Serial.println(hum);

    if (WiFi.status() != WL_CONNECTED) {
      Serial.println(F("Disconnect"));
    } else {
      Serial.println(F("-------------------")); 
      Serial.println(F("Wifi Connect"));
    }

  }

  if (currentMillis - previousMillis_ts >= ts_update_interval) {
    previousMillis_ts = currentMillis;
    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);
      WiFi.begin(ssid, pass);
      int i = 0;
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        ++i;

        if (i == 20) {
          i = 0;
          Serial.println("\n Failed to Connect.");
          break;
        }
      }
    }

    ThingSpeak.setField(1, lat_data);  //field latitude
    ThingSpeak.setField(2, lng_data);
    ThingSpeak.setField(3, hum);  //field humidity
    ThingSpeak.setField(4, temp); //field temperature
    // write to the ThingSpeak channel
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if (x == 200) {
      Serial.println("Sukses Update Chanel.");
    } else {
      Serial.println("Update Chanel Bermasalah. HTTP error code " + String(x));
    }
    Serial.println();
  }
}


void ConnectWIFI() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    //WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass); //Untuk Simulasi >> Spesifik channel 6
    int i = 0;
    int a = 0;
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      Serial.println(F("Connecting"));
      delay(1000);
      ++i;
      if (i == 30) {
        i = 0;
        Serial.println("\n Failed to Connect.");
        break;
      }
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\n Connected!");
    } else {
      Serial.println(F("Failed"));
    }
    delay(3000);
  }
}

