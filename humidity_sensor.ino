#include <DHT.h>
#define DHTPIN 2     // Data pin connected to D2
#define DHTTYPE DHT11    // dht11 sensor
DHT dht(DHTPIN, DHTTYPE);
void setup(){
	Serial.begin(9600);
	Serial.println("DHT11 Temperature & Humidity Sensor");
	dht.begin();
}
void loop(){
	float humidity = dht.readHumidity();
	float temperature = dht.readTemperature();
	float tempF = dht.readTemperature(true);
if ( isnan(humidity) || isnan(temperature) ){
	Serial.println("Failed to read from DHT11 sensor!");
	delay(2000);
	return;
}
Serial.print("Humidity:" );
Serial.print(humidity);
Serial.print( "  % | ");

Serial.print(" Temperature: ");
Serial.print(temperature);
Serial.print(" 0 C  /  ");
Serial.print(tempF);
Serial.println(" 0 F ");
delay(3000);
}
