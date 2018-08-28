/***************************************************************************
  This was adapted from a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Hint: the default I2C address used by the library is (0x77), as in
  Adafruit_BME280.h. If you sensor board uses a different address you
  can set your own via the .begin(...) method.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  This file was modified by Markus Haack (https://github.com/mhaack)
  in order to work with Particle Photon & Core.

  This file was modified by Eric Zhang (https://github.com/ericsibored)
  in order to report data to Particle Cloud 
 ***************************************************************************/

#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"

#define BME_SCK D1
#define BME_MOSI D0


#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);


double temp;
double humidity;

void setup() {
    
  Particle.variable("temp", temp);
  Particle.variable("humidity", humidity);
  
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  // if (!bme.begin(0x76)) {
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // The core of your code will likely live here.

  float t = bme.readTemperature(); // *C
  float h = bme.readHumidity(); // %
  //float p = bme.readPressure() / 100.0F; // hPa
  //float a = bme.readAltitude(SEALEVELPRESSURE_HPA);
  
  temp = (t*9/5) + 32.00; //Celsius to Fahrenheit conversion
  humidity = h;

  //formatting sensor data into string message
  String data = String::format("%.2f",temp) + " degrees F, " + "humidity "+ String::format("%.2f",h) + "%";

  // Publish data to Particle Cloud
  Particle.publish("data", data,PRIVATE);

  delay(5000);
}

