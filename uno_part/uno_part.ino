#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0,0);

  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  String mHumidity =    "Hum  :     " + String(humidity);
  String mTemperature = "Temp :     " + String(temperature);

  String raw = String(humidity) + "," + String(temperature) + "\n";
  Serial.write(raw.c_str());

  lcd.setCursor(0,0);
  lcd.print(mHumidity);
  lcd.setCursor(0,1);
  lcd.print(mTemperature);
  
  delay(500);
}
