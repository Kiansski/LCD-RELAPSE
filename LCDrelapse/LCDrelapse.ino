/*
   Arduino LCD I2C Tutorial by 'Tronics Lk"
   Please visit my YouTube channel from this link for more Tutorials
   https://www.youtube.com/channel/UCYJa3gs8q49-N3TLm-7ygUw?sub_confirmation=1
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("-Miss mo na?");
  delay(3000);
  lcd.setCursor(0, 1);
  lcd.print("-Sobra :((");
  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Hindi na");
  lcd.setCursor(0, 1);
  lcd.print("Makalaya");
  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Dinadalaw mo'ko");
  lcd.setCursor(0, 1);
  lcd.print("bawat gabi.");
  delay(10000);
  lcd.clear();
}
