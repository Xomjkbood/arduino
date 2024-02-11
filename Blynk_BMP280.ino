
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BLYNK_PRINT Serial
#define BLYNK_AUTH_TOKEN "token_Blynk"

Adafruit_BMP280 bmp;

float temperature;
float pressure;

char auth[] = BLYNK_AUTH_TOKEN;
const char* ssid     = "SSID";
const char* password = "passSSID";
String header;

void setup(){
  bmp.begin();
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password, "blynk.tk", 8080);
}

void loop(){
  temperature = bmp.readTemperature();
  pressure = (bmp.readPressure() / 100.0F) / 1.333;
  Blynk.virtualWrite(V5, temperature);
  Blynk.virtualWrite(V7, pressure);
  Blynk.run();
}
