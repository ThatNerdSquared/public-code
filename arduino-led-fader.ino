// Arduino Script: LED Fader
// Copyright 2020 Nathan Yeung
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the Software), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// Init LCD.
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// const for LED output pin.
#define pLED 9

void setup() {
	// Init for serial monitor
	Serial.begin(9600);
	// Setting output for LED pin.
	pinMode(pLED, OUTPUT);
	// Setting up the LCD
	lcd.begin(16, 2);
	lcd.setCursor(0,0);
	// Init LCD tutorial.
	lcd.print("Type 1-4 to");
	lcd.setCursor(0,1);
	lcd.print(" adjust light");
	delay(1500);
	lcd.noDisplay();
}

// Function for the fades.
void fade(int l) {
	for (int i = 0; i < 256; i=i+l)
	{
		Serial.println(i);
		analogWrite(pLED, i);
	}
	delay(1500);

	for (int i = 255; i > -1; i=i-l)
	{
		Serial.println(i);
		analogWrite(pLED,i);
	}
}

// Function to dispay light level on the LCD.
void displayLevel(int l) {
	lcd.begin(16, 2);
	lcd.setCursor(0,0); // col,row
	lcd.print("Fade speed level:");
	lcd.setCursor(0,1);
	lcd.print(l);
	delay(1500);
	lcd.noDisplay();
}

void loop() {
	if (Serial.available() > 0) {

		// Reading the fade speed from the serial monitor.
		char rx = Serial.read();

		// Converting input into an int, the brute-force way.
		if (rx == '1') {
			int l = 1;
			// calling functions the noob way
			displayLevel(l); // invoke function for LCD level
			fade(l); // invoke function for fading
		}
		else if (rx == '2') {
			int l = 2;
			// calling functions the noob way
			displayLevel(l); // invoke function for LCD level
			fade(l); // invoke function for fading
		}
		else if (rx == '3') {
			int l = 3;
			// calling functions the noob way
			displayLevel(l); // invoke function for LCD level
			fade(l); // invoke function for fading
		}
		else if (rx == '4') {
			int l = 4;
			// calling functions the noob way
			displayLevel(l); // invoke function for LCD level
			fade(l); // invoke function for fading
		}

	}
}