#include <Keypad.h>  // Bibliteca do Teclado
#include <Wire.h>  // Biblioteca LCD
#include <LiquidCrystal_I2C.h>  // Biblioteca LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);  // lcd(Endereço I2C, Colunas, Linhas)

// Definindo pinos de linhas e colunas conecadas no arduino
byte pinosLinhas[ ]  = {4,5,6,7};
byte pinosColunas[ ] = {10,9,8};

// Matriz responsavel pela impressão no lcd
char teclas[4][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                     {'*','0','#'}};

Keypad teclado1 = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 3);  

void setup(){
    lcd.init();  // Inicializa o lcd
    lcd.backlight();  // Liga a Luz de Fundo
    lcd.print("Teclado e Lcd");
    lcd.setCursor(0, 1);
    lcd.print("Tecla: ");   
    lcd.setCursor(7, 1); 
        Serial.begin(9600);  // Inicia a Serial
        Serial.println("Teste Teclado e Lcd");
        Serial.println();
}

void loop() {

  char tecla_pressionada = teclado1.getKey();  //Localiza a tecla pressionada e adiciona em uma variável
  
  if (tecla_pressionada)  
  { // Imprime no Lcd e no Serial
    Serial.print("Tecla: ");
    Serial.println(tecla_pressionada);
    lcd.print(tecla_pressionada);
  } 
}