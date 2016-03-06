#include <LiquidCrystal.h>
#include <dht.h>
#include <string.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
double humidity;
double temp;

void setup() {
	// Initialize the lines and columns of display will be used.
  	lcd.begin(16, 2);
	
	lcd.print("    Welcome!"); // Extra spacing added for alignment purpose.
  	
	// Wait for one second
	delay(1000);
 	
	//Clear the display for displaying the data.
	lcd.clear();
}

void loop() {
	// Fetching data from the sensor.
    DHT.read11(A0);
	
	// Store the weather information in a global variable.
    humidity = DHT.humidity;
    temp = DHT.temperature;
    
	//Print the Temperature information on the display.
	lcd.print("TEMP:");
	lcd.print(temp);
    lcd.print("C");
	
	//Set the cursor so the print start from the index 1, which is the second line.
    lcd.setCursor(0, 1);
    
	// Print the humidity information on the display.
	lcd.print("HUMI:");
    lcd.print(humidity);
    lcd.print("%");
	
	// Wait for a second.
    delay(1000);
    lcd.clear();
} 

