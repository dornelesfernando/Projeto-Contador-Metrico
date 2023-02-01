#include <Wire.h>  // Biblioteca LCD
#include <LiquidCrystal_I2C.h>  // Biblioteca LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);  // lcd(Endereço I2C, Colunas, Linhas)

# define rele 13  // Relé conectada ao pino 13 do arduino

// Variáveis
// Sensor de Contagem
volatile int cont = 0;  // Contagem de furos do disco encoder
int contadorVoltas = 0;  // Contagem de voltas do disco encoder

// Botão de limpar
const int botaoLimpa = 11;  // Botão conectado ao pino 11 do arduino
int statusDoBotaoLimpa = 0;  // Variável que controla o botão

int valorPedido = 0;
float metrosPorVolta = 0.10;
int voltasEncoder = 0;


void setup(){
    pinMode(rele, OUTPUT);
    pinMode(botaoLimpa, INPUT);
    pinMode(3, INPUT);
    attachInterrupt(digitalPinToInterrupt(3), interrupcao, RISING);

    lcd.init();  // Inicializa o lcd
    lcd.backlight();  // Liga a Luz de Fundo
    lcd.print("Val. Pedido:   m");
    lcd.setCursor(0, 1);
    lcd.print("Valor atual:   m");   
    lcd.setCursor(8, 2); 
        Serial.begin(9600);  // Inicia a Serial
        Serial.println("Contagem iniciada");
        Serial.println();

}

void loop(){
  valorPedido = 1;
  voltasEncoder = valorPedido / metrosPorVolta;
  Serial.println(voltasEncoder);











/*statusDoBotaoLimpa = digitalRead(botaoLimpa);
if (statusDoBotaoLimpa == HIGH)
  limpa();
}  */
}

void interrupcao (){
    cont++;
    
    if(cont == 20){
        contadorVoltas++;
        cont = 0;
      }
}

void limpa(){
  valorPedido = 0;
}
