#include <Wire.h>  // Biblioteca LCD
#include <LiquidCrystal_I2C.h>  // Biblioteca LCD

LiquidCrystal_I2C lcd(0x27, 16, 2);  // lcd(Endereço I2C, Colunas, Linhas)

# define rele 13  // Relé conectada ao pino 13 do arduino

// Variáveis
// Sensor de Contagem
volatile int cont = 0;  // Contagem de furos do disco encoder
int contadorVoltas = 0;  // Contagem de voltas do disco encoder

int valorPedido = 0;
float metrosPorVolta = 0.10;
int voltasEncoder = 0;
int valorAtual = 0;


void setup(){
    pinMode(rele, OUTPUT);
    pinMode(3, INPUT);
    attachInterrupt(digitalPinToInterrupt(3), interrupcao, RISING);

    lcd.init();  // Inicializa o lcd
    lcd.backlight();  // Liga a Luz de Fundo
    lcd.print("Val. Pedido:   m");
    lcd.setCursor(0, 1);
    lcd.print("Valor atual:   m");   
        Serial.begin(9600);  // Inicia a Serial
        Serial.println("Contagem iniciada");
        Serial.println();
}

void loop(){
  delay(1000);
  valorPedido = 10;
  lcd.setCursor(13, 0);
  lcd.print(valorPedido);
  Serial.println("Valor pedido: ");
  Serial.println(valorPedido);
 
  voltasEncoder = valorPedido / metrosPorVolta;
  
  for(contadorVoltas; contadorVoltas <= voltasEncoder; interrupcao()){
      digitalWrite(rele, HIGH);

      valorAtual = contadorVoltas * metrosPorVolta;
      lcd.setCursor(13, 1);
      lcd.print(valorAtual);
      Serial.println("Valor Atual: ");
      Serial.println(valorAtual);
        if(contadorVoltas == voltasEncoder){
          digitalWrite(rele, LOW);
        }
    }
}

void interrupcao (){
    cont++;
    
    if(cont == 20){
        contadorVoltas++;
        cont = 0;
      }
}
