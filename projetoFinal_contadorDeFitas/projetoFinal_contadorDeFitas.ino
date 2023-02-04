#include <Keypad.h>  // Bibliteca do Teclado
#include <Wire.h>  // Biblioteca LCD
#include <LiquidCrystal_I2C.h>  // Biblioteca LCD

# define rele 13  // Relé conectada ao pino 13 do arduino

LiquidCrystal_I2C lcd(0x27, 16, 2);  // lcd(Endereço I2C, Colunas, Linhas)

  // Variáveis
// Definindo pinos de linhas e colunas conecadas no arduino
byte pinosLinhas[ ]  = {4,5,6,7};
byte pinosColunas[ ] = {10,9,8};

// Matriz responsavel pela impressão no lcd
char teclas[4][3] = {{'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'},
                     {'*','0','#'}};

Keypad teclado1 = Keypad( makeKeymap(teclas), pinosLinhas, pinosColunas, 4, 3);  

// ---------------------------------------

// Sensor de Contagem
volatile int cont = 0;  // Contagem de furos do disco encoder
int contadorVoltas = 0;  // Contagem de voltas do disco encoder

// Botão
const int botaoDesliga = 12;  // Botão conectado ao pino 12 do arduino
int statusDoBotaoDesliga = 0;

// Botão
const int botaoLiga = 11;  // Botão conectado ao pino 12 do arduino
int statusDoBotaoLiga = 0;  

int valorPedido = 0;
float centimetrosPorVolta = 10;
int voltasEncoder = 0;
int valorAtual = 0;

bool desliga = false;
static String valorConfigurado = "";

void setup(){
    pinMode(rele, OUTPUT);
    pinMode(3, INPUT);
    pinMode(botaoLiga, INPUT);
    pinMode(botaoDesliga, INPUT);
    attachInterrupt(digitalPinToInterrupt(3), interrupcao, RISING);

    lcd.init();  // Inicializa o lcd
    lcd.backlight();  // Liga a Luz de Fundo
    lcd.print("Val. Confg: ");
    lcd.setCursor(0, 1);
    lcd.print("Val. atual: ");  
        Serial.begin(9600);  // Inicia a Serial
        Serial.println("Contagem iniciada");
        Serial.println();       
}

void loop(){
     statusDoBotaoLiga = digitalRead(botaoLiga);   
       if (statusDoBotaoLiga == HIGH){
          for(contadorVoltas; contadorVoltas <= voltasEncoder; interrupcao()){
            
              digitalWrite(rele, HIGH);
              valorAtual = contadorVoltas * centimetrosPorVolta;
              lcd.setCursor(12, 1);
              lcd.print(valorAtual);
//              Serial.println("Valor Atual: ");
//              Serial.println(contadorVoltas);

         
            statusDoBotaoDesliga = digitalRead(botaoDesliga);
              if(statusDoBotaoDesliga == HIGH){
                  contadorVoltas = voltasEncoder + 1;
                  desliga = true;
                  if(desliga == true){
                      digitalWrite(rele, LOW);
                      delay(1000);
                      lcd.clear();
                      lcd.print("Finalizado");
                      delay(2000);
                      lcd.clear();
                      lcd.print("Val. Confg: ");
                      lcd.setCursor(0, 1);
                      lcd.print("Val. atual: ");  
                      valorConfigurado = "";  
                      Serial.println(valorConfigurado); 
                   }
               }
                           
              if(desliga == true || contadorVoltas >= voltasEncoder){
                digitalWrite(rele, LOW);
             }
           }   
        }
     
     char tecla_pressionada = teclado1.getKey();  //Localiza a tecla pressionada e adiciona em uma variável
          if(tecla_pressionada){
              static String valorConfigurado = "";
              valorConfigurado += tecla_pressionada;
              lcd.setCursor(12,0);
              lcd.print(valorConfigurado);
              Serial.println(valorConfigurado);
              int valorPedido = valorConfigurado.toInt();
              voltasEncoder = valorPedido / centimetrosPorVolta;
           }         
}

void interrupcao (){
    cont++;
    
    if(cont == 20){
        contadorVoltas++;
        cont = 0;
      }
}
