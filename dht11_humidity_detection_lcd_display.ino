//www.elegoo.com
//2018.10.25

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 7       
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2);
  dht.begin();

  Serial.begin(9600);

  lcd.print("Sensor Starting");
  delay(2000);
  lcd.clear();
}

void loop() {

  delay(2000);    // gives dht11 time to read temperature and humidity + lcd to display

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.print("Sensor Error");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  lcd.clear();

  // serial output for debugging purposes / in case there are lcd display issues
  Serial.print("T = ");
  Serial.print(temperature);
  Serial.print(" C, H = ");
  Serial.print(humidity);
  Serial.println("%");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");
}
