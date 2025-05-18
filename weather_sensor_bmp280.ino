#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <SD.h>

const int chipSelect = 10;
const char* FILENAME = "weather.txt";

Adafruit_BMP280 bmp;
File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("failed. Check wiring and card!");
    while (1);
  }
  Serial.println("done.");

  if (!SD.exists(FILENAME)) {
    Serial.print("Creating ");
    Serial.println(FILENAME);
    myFile = SD.open(FILENAME, FILE_WRITE);
    if (myFile) {
      myFile.println("Millis,Temperature,Pressure,Altitude");
      myFile.close();
      Serial.println("File created and header written.");
    } else {
      Serial.println("Error: could not create file.");
    }
  } else {
    Serial.print(FILENAME);
    Serial.println(" already exists.");
  }

  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 sensor not found! Check wiring.");
    while (1);
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);
}

void writeData() {
  unsigned long currentMillis = millis();
  myFile = SD.open(FILENAME, FILE_WRITE);
  Serial.println("Opening data file...");

  if (myFile) {
    float temperature = bmp.readTemperature();
    float pressure = bmp.readPressure();
    float altitude = bmp.readAltitude(1013.25);

    if (isnan(temperature) || isnan(pressure) || isnan(altitude)) {
      Serial.println("ERROR: Invalid sensor reading");
      myFile.close();
      return;
    }

    myFile.print(currentMillis);
    myFile.print(',');
    myFile.print(temperature);
    myFile.print(',');
    myFile.print(pressure);
    myFile.print(',');
    myFile.println(altitude);
    myFile.close();

    Serial.print(currentMillis); Serial.print(',');
    Serial.print(temperature); Serial.print(',');
    Serial.print(pressure); Serial.print(',');
    Serial.println(altitude);
  } else {
    Serial.println("Failed to open data file");
  }
}

void loop() {
  Serial.println("Writing sensor data...");
  writeData();
  delay(2000);
}
