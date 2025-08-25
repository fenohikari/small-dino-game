#include <Arduino.h>
#include <LiquidCrystal.h>
int echo = 4;
int trigger = 5;
int buzzer = 6;
float TotalT = 0;
float Speed = 0.0343; // Speed of sound in cm/us
float Distance = 0;
int backlight = 3; // Backlight pin for LiquidCrystal


// LiquidCrystal pins
const int rs = 12, en = 11, d4 = 10, d5 = 7, d6 = 8, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(backlight, OUTPUT);

}

void loop() {
  analogWrite(backlight, 100); // Turn on the backlight
  lcd.setCursor(0, 0);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  TotalT = pulseIn(echo, HIGH);
  Distance = 400 - 65 - (TotalT * Speed) / 2;
  Serial.println(TotalT);
  if (Distance < 300) {
    lcd.print(Distance);
    lcd.print("cm");
  }

  else {
    lcd.print("Full!!");
    lcd.print("    ");
  }

  delay(1000);
}