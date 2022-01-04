/* 
    SERIAL PASSTHROUGH FOR GPS MODULE
    ---------------------------------
*/

// include header dan library
#include <SoftwareSerial.h>

// konstanta untuk mengatur koneksi, ubah sesuai kebutuhan
#define GPS_PIN_RX D1
#define GPS_PIN_TX D2

// objek serial untuk berkomunikasi dengan modul GPS
SoftwareSerial gps_serial(GPS_PIN_RX, GPS_PIN_TX);

// kode ini dieksekusi sekali saat ESP8266 diinisialisasi
void setup()
{
    Serial.begin(9600);
    gps_serial.begin(9600);
}

// kode ini dieksekusi terus-menerus
void loop()
{
    if (Serial.available())
    {
        gps_serial.write(Serial.read());
    }

    if (gps_serial.available())
    {
        Serial.write(s.read());
    }
}
