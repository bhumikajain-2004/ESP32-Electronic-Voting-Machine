#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int candidateA = 13;
const int candidateB = 12;
const int candidateC = 14;
const int resultBtn = 27;

int votesA = 0;
int votesB = 0;
int votesC = 0;

void setup() {
  pinMode(candidateA, INPUT_PULLUP);
  pinMode(candidateB, INPUT_PULLUP);
  pinMode(candidateC, INPUT_PULLUP);
  pinMode(resultBtn, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("EVM Using ESP32");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  delay(2000);

  lcd.clear();
  lcd.print("Cast Vote");
}

void loop() {

  if (digitalRead(candidateA) == LOW) {
    votesA++;
    lcd.clear();
    lcd.print("Vote: Cand A");
    delay(500);
    lcd.clear();
    lcd.print("Cast Vote");
  }

  if (digitalRead(candidateB) == LOW) {
    votesB++;
    lcd.clear();
    lcd.print("Vote: Cand B");
    delay(500);
    lcd.clear();
    lcd.print("Cast Vote");
  }

  if (digitalRead(candidateC) == LOW) {
    votesC++;
    lcd.clear();
    lcd.print("Vote: Cand C");
    delay(500);
    lcd.clear();
    lcd.print("Cast Vote");
  }

  if (digitalRead(resultBtn) == LOW) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("A:");
    lcd.print(votesA);
    lcd.print(" B:");
    lcd.print(votesB);

    lcd.setCursor(0, 1);
    lcd.print("C:");
    lcd.print(votesC);

    delay(5000);

    lcd.clear();
    lcd.print("Cast Vote");
  }
}