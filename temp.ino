// Include library for DHT11 temp sensor
#include <Adafruit_DHT.h>

#define DHTPIN 6            // Defines pin we are connected to, which is pin 6
#define DHTTYPE DHT11      // DHT 11 (DHT type)

DHT dht(DHTPIN, DHTTYPE);   // Initialises the DHT11 sensor

void setup() {
    Serial.begin(9600); //baud rate 9600
    dht.begin();
}



void loop() {
    // Variables
    float temp; 
    
    // Reads the temperature data and stores it to the variables specified above. 
    temp= dht.getTempCelcius();
    
    // Prints the values to the serial monitor, in this case humidity and temp
    Serial.printlnf("Temp: %f celsius", temp);
    
    // Publishes to thingspeak API
    Particle.publish("temp", String(temp), PRIVATE);
    
    // Delay 30 seconds
    delay(30000); 
}