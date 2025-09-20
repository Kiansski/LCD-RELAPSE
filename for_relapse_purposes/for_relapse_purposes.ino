#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int btn = 8;
bool lastButtonState = HIGH;  // assume not pressed initially
bool triggered = false;
bool currentButtonState;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(btn, INPUT_PULLUP);  // use internal pull-up resistor
  Serial.begin(9600); 
}

void loop() {

currentButtonState = digitalRead(btn);

  // Detect falling edge (button just pressed)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    triggered = true;
  }

  lastButtonState = currentButtonState; // keeps track the last state

  if (triggered) {
    triggered = false;  // reset so it doesn't repeat
    displayMessage();   // run your message function
  }

  else{
  lcd.setCursor(2,0);
  lcd.print("RELAPSE TIME");
  lcd.setCursor(3,1);
  lcd.print(">PRESS ME<");
  }
}

//made a function to easily organize the code just incase im gonna add anything in the future :)))))
void displayMessage() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("How can we go");
  delay(2500);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Back to");
  delay(1000);
  lcd.setCursor(1, 1);
  lcd.print("Being friends?");
  delay(1500);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("When we");
  delay(800);
  lcd.setCursor(1, 1);
  lcd.print("Just shared");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("A BED...");
  delay(5000);
  lcd.clear();
  delay(10000);
}
