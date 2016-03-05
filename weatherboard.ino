#include <LiquidCrystal.h>
#include <dht.h>
#include <string.h>

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
    lcd.print("TEMP:");
	  lcd.print(temp);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print("HUMI:");
    lcd.print(humidity);
    lcd.print("%");
    delay(1000);
    lcd.clear();
} 

