#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int BUTTON_PIN = 2;
int cactus_x = 15;
int dino_y = 1;
bool game_over = false;
int score = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  show();
}

void loop() {
  if(game_over) {
    if(digitalRead(BUTTON_PIN)) {
      score = 0;
      game_over = false;
    }
  } else {
    score++;
    move_cactus();
    
    if(digitalRead(BUTTON_PIN)) {
      dino_y = 0;
      show();
      
      move_cactus();
      show();
  
      move_cactus();
    }
  
    dino_y = 1;
    show();
    
    if(cactus_x == 0) {
      game_over = true;
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("Game Over!");
    }
  }
}

void show() {
  lcd.clear();
  lcd.setCursor(cactus_x, 1);
  lcd.print("C");
  lcd.setCursor(0, dino_y);
  lcd.print("D");
  lcd.setCursor(4, 0);
  lcd.print(score);
  delay(250);
}

void move_cactus() {
  cactus_x--;
  if(cactus_x < 0) {
    cactus_x = 15;
  }
}
