#include <Keypad.h>

byte pinosLinhas[ ]  = {4,5,6,7};

byte pinosColunas[ ] = {10,9,8};

char teclas[4][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                     {'L','0','O'}};

Keypad teclado1 = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 3);  

void setup() {
  Serial.begin(9600);
  Serial.println("Teclado 4x3");
  Serial.println("Teclado Matricial Iniciado");
  Serial.println();
}

void loop() {

  char tecla_pressionada = teclado1.getKey();
  
  if (tecla_pressionada)
  {
    Serial.print("Tecla: ");
    Serial.println(tecla_pressionada);
  } 
}
