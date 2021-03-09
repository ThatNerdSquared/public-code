#include <LiquidCrystal.h>

#define RS 2
#define EN 3
#define D4 8
#define D5 9
#define D6 10
#define D7 11

#define enA 1
#define in1 12
#define in2 13

String inPut = String(""); 

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Password Please");

  // Turn motor off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  Serial.begin(9600);
  String inPut = String(); 
  String pressed = String("0");
}

void pressed(String pressed) {
  int lengthCheck = inPut.length();
  if (lengthCheck < 4) {
    String newPut = inPut + pressed;
    inPut = newPut;
    lcd.setCursor(0,1);
  	lcd.print(inPut);
  }
  else if (inPut != "3241") {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("INCORRECT!");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password Please");
    inPut = String();
  }
  else if (inPut == "3241") {
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password Correct!");
    Serial.println("set_speed");
    analogWrite(enA, 255);
    Serial.println("spin_start");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(10000);
    Serial.println("motor_go_bye_bye");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Password Please");
    inPut = String();
  }
  delay(1000);
}  

void loop() {
  int a = digitalRead(4);
  int b = digitalRead(5);
  int c = digitalRead(6);
  int d = digitalRead(7);
  

  String pressedVal = String("0");
  
  if (a == 1) {
    pressedVal = "1";
    pressed(pressedVal);
  }
  if (b == 1) {
    pressedVal = "2";
    pressed(pressedVal);
  }
  if (c == 1) {
    pressedVal = "3";
    pressed(pressedVal);
  }
  if (d == 1) {
    pressedVal = "4";
    pressed(pressedVal);
  }
}
