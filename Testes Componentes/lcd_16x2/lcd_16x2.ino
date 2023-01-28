#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int t= 60;  // Variável de controla o tempo em que o cronometro estará ativo

void setup() {
lcd.init();  // *
lcd.backlight();  // *
Serial.begin(9600);
Serial.println("Cronometro Teste"); 
Serial.println("Tempo: ");
for (int i = 0; i <= t; i++) {  
  lcd.clear();  
  lcd.print("Cronometro Teste");   
  lcd.setCursor(0, 1);  
  lcd.print("Tempo: ");   
  lcd.setCursor(7, 1);  
  lcd.print(i);
Serial.print("-> ");
Serial.println(i);
delay(1000);
}

lcd.clear();  // Limpa a tela para reiniciar
lcd.print("Fim!");
Serial.print("Fim!");
}

void loop() {}
