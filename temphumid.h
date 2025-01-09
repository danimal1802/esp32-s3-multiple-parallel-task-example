#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

// Create an AHTX0 object (supports AHT10, AHT20, AHT21)
Adafruit_AHTX0 aht;

void temphumid_sketch(void *parameter) {
    // Setup start here
    //pinMode(LED_2_PIN, OUTPUT);
    Serial.begin(115200); 
    delay(100);  // Give time for the Serial to initialize

    // Initialize I2C communication
    // If your board uses different pins for SDA/SCL, specify them:
    // e.g.: Wire.begin(20, 21);
    Wire.begin();
    
    // Initialize the AHT20 sensor
    if (!aht.begin()) {
      Serial.println("Failed to find AHT20 sensor! Check wiring/I2C address.");
      while (1) {
        delay(10);  // Halt program
      }
    }
    Serial.println("AHT20 initialized successfully!");


    // End of your setup
    
    // Loop function, run repeatedly
    for (;;) {
        sensors_event_t humidity, temp;
  
        // Request a reading
        aht.getEvent(&humidity, &temp);

        // Print temperature (in °C) and humidity (%)
        Serial.print("Temperature: ");
        Serial.print(temp.temperature);
        Serial.print(" °C,  Humidity: ");
        Serial.print(humidity.relative_humidity);
        Serial.println(" %");

        delay(2000);  // Read data every 2 seconds
    }
}
