#include <LiquidCrystal.h>
#include <dht.h>
#include <string.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
double humidity;
double temp;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  delay(1000);
 
}

void loop() {
    DHT.read11(A0);
    humidity = DHT.humidity;
    temp = DHT.temperature;
    lcd.print(humidity);
	  lcd.setCursor(0, 1);
	  lcd.print(temp);
    delay(1000);
    lcd.clear();
} 

