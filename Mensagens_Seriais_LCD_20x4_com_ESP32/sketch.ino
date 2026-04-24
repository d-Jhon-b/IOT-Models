//link do repositório: https://github.com/d-Jhon-b/IOT-Models.git
//link do exemplo no wolki: https://wokwi.com/projects/462145869330287617

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int coluna = 0; 
void setup() {
  Serial.begin(115200);
  
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.println("--- Pronto para receber mensagens ---");
  Serial.println("Digite os caracteres no terminal:");
}
void loop() {
  if (Serial.available() > 0) {
    char caractere = Serial.read();

    if (caractere == '\n' || caractere == '\r') {
      return; 
    }

    if (coluna >= 20) {
      lcd.clear();
      coluna = 0;
    }

    // Escreve na linha 0 (Normal)
    lcd.setCursor(coluna, 0);
    lcd.print(caractere);

    // Escreve na linha 1 (Maiúsculo)
    lcd.setCursor(coluna, 1);
    lcd.print((char)toupper(caractere)); 

    coluna++;
  }
  
  // Um delay bem pequeno (10ms) é suficiente para estabilidade 
  // e não aciona o Watchdog.
  delay(10); 
}