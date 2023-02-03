#include <Wire.h>  // Biblioteca LCD
#include <LiquidCrystal_I2C.h>  // Biblioteca LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);  // lcd(Endereço I2C, Colunas, Linhas)

// Variáveis
volatile int cont = 0;  // Contagem de furos do disco encoder
int voltas = 0;  // Contagem de voltas do disco encoder

void setup(){
    pinMode(3, INPUT);
    attachInterrupt(digitalPinToInterrupt(3), interrupcao, RISING);

    lcd.init();  // Inicializa o lcd
    lcd.backlight();  // Liga a Luz de Fundo
    lcd.print("Contagem iniciada");
    lcd.setCursor(0, 1);
    lcd.print("Voltas: ");   
        Serial.begin(9600);  // Inicia a Serial
        Serial.println("Contagem iniciada");
        Serial.println();
}

void loop(){
    delay(1000);
    lcd.setCursor(8, 1); 
    lcd.print(voltas);
    Serial.print("Quantidade de voltas: ");
    Serial.println(voltas);
}

void interrupcao (){
    cont++;
    
    if(cont == 20){
        voltas++;
        cont = 0;
      }
}
