#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
DHT dht(7, DHT11);

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <Wire.h>
#include <RtcDS3231.h>
RtcDS3231<TwoWire> clock(Wire);


void setup() {
  lcd.begin(16, 2);
  clock.Begin();
  dht.begin();
  

}

void loop() { 
  lcd.setCursor(0, 0);
  RtcDateTime now = clock.GetDateTime(); 
  lcd.print(now.Hour());
  lcd.print(":");
  lcd.print(now.Minute());
  lcd.setCursor(6, 0);
  lcd.print(now.Day());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Year());

  
  lcd.setCursor(0, 1);
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.setCursor(9, 1);
  lcd.print("Hum:");
  lcd.print(humidity);
  
  
  
  
  

  
  

 

}
