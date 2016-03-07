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

  // If the temperature passed has been changed, then update.
  // This will minimize the refersh frequency result in a minimal power comsumption.
  if (temp != DHT.temperature){
    temp = DHT.temperature;
    lcd.setCursor(0, 0);
    lcd.print("TEMP:");
  	lcd.print(temp);
    lcd.print("C");
  }
  else {
    // Do nothing
  }

  if (humidity != DHT.humidity){
    humidity = DHT.humidity;
    lcd.setCursor(0, 1);
    lcd.print("HUMI:");
    lcd.print(humidity);
    lcd.print("%");
  }

  else {
    // Do nothing
  }


	// Wait for a second.
    delay(1000);
    lcd.clear();
}
