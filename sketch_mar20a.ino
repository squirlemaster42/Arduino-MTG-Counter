#include <LiquidCrystal.h>.

int red = 8;
int green = 6;
int blue = 7;
int up = 10;
int down = 13;
int reset = 9;
int life = 20;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(1200);
  lcd.begin(16, 2);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(reset, INPUT);
}

void loop() {
  int upLife = digitalRead(up);
  int downLife = digitalRead(down);
  int resetLife = digitalRead(reset);
  
  if (life == 0){
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
    delay(1000);
    digitalWrite(blue, HIGH);
    delay(1000);
    digitalWrite(blue, LOW);
    delay(1000);
    digitalWrite(red, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    delay(1000);
  }
  if (upLife == HIGH){
    life += 1;
  }
  if (downLife == HIGH){
    life -= 1;
  }
  if (resetLife == HIGH){
    lcd.clear();
    delay(1000);
    life = 20;
  }
  lcd.setCursor(0, 1);
  lcd.clear();
  lcd.print(life);
  Serial.println(life);
  delay(500);
}
