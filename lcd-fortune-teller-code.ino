//// Arduino Script: LCD Fortune Teller
// Copyright 2020 Nathan Yeung
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the Software), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long choice;


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0); // col,row
  lcd.print("Press a button");
  lcd.setCursor(0,1);
  lcd.print("Get a fortune");
  pinMode(13,INPUT);
  randomSeed(analogRead(0)); // seed random generator
  Serial.begin(9600);
}

void loop() {
  int but1 = digitalRead(13);
  int choice = random(0,9);
  Serial.println(choice);
  if (but1 == HIGH) { // detect button press
    lcd.noDisplay();
    lcd.begin(16,2);
    if (choice == 0) {
      lcd.print("You are roflsob");
    }
    else if (choice == 2) {
      lcd.print("Start pomming");
    }
    else if (choice == 3) {
      lcd.print ("Stop procrastinating");
    }
    else if (choice == 4) {
      lcd.print("Calm down");
    }
    else if (choice == 5) {
      lcd.print("Yes.");
    }
    else if (choice == 6) {
      lcd.print("No.");
    }
    else if (choice == 7) {
      lcd.print("Maybe.");
    }
    else if (choice == 8) {
      lcd.print("HELL NO");
    }
    else if (choice == 9) {
      lcd.print("HELL YES");
    }
    else if (choice == 1) {
      lcd.print("Uh no comment");
    }
    else {
      Serial.println(choice);
    }
  }
  delay(500);
  lcd.noDisplay();
}
