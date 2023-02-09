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

// Sensor de Contagem
volatile int cont = 0;  // Contagem de furos do disco encoder
int contadorVoltas = 0;  // Contagem de voltas do disco encoder

// Botão Desliga
const int botaoLiga = 11;  // Botão conectado ao pino 12 do arduino
int statusDoBotaoLiga = 0; 

// Botão Desliga
const int botaoDesliga = 12;  // Botão conectado ao pino 12 do arduino
int statusDoBotaoDesliga = 0;

// Variáveis gerais
int valorPedido = 0;  // Armazena o valor informado pelo usuário
float centimetrosPorVolta = 10;  // Alterar para o valor em centimetros que seu motor faz por volta
int voltasEncoder = 0;  // Armazena a quantidade de voltas que o motor terá que dar para satisfazer o pedido do usuário
int valorAtual = 0;  // Monitora a distância já percorrida
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
}

void loop(){
     statusDoBotaoLiga = digitalRead(botaoLiga);   
       if (statusDoBotaoLiga == HIGH){  // Se o botão iniciar for apertado
          
          for(contadorVoltas; contadorVoltas <= voltasEncoder; interrupcao()){  
              char tecla_pressionada = teclado1.getKey();
                if(tecla_pressionada){  // Se a tecla "#" for pressionada, pausa o motor
                    if(tecla_pressionada == '#'){
                       return;
                    }
                }  
              
              digitalWrite(rele, HIGH);  // Liga relé
              valorAtual = contadorVoltas * centimetrosPorVolta;  // Inicia/atualiza a variável de controle
              lcd.setCursor(12, 1);
              lcd.print(valorAtual);  // Mostra no Lcd
         
            statusDoBotaoDesliga = digitalRead(botaoDesliga);
              if(statusDoBotaoDesliga == HIGH){  // Se o botão resetar for pressionado
                  desliga = true;
                  if(desliga == true){  // Desliga a relé
                      digitalWrite(rele, LOW);           
                   }
                  resetar();  // Reseta as variáveis de controle
               }
                           
              if(desliga == true || contadorVoltas >= voltasEncoder){  // Se a variável de controle for ativada ou o motor completar as volas
                digitalWrite(rele, LOW);  // Desliga relé       
              }
           }
         completo();  // Reinicia parcialmente o sistema, não reseta as variáveis de controle dos valores informados pelo usuário   
        }
       else{
          digitalWrite(rele, LOW);  // Caso o botão iniciar não seja apertado a relé permanece desligada  
        }

        statusDoBotaoDesliga = digitalRead(botaoDesliga);
          if(statusDoBotaoDesliga == HIGH){  // // Se o botão resetar for pressionado durante o pause ou sem iniciar reseta o sistema completamente
             contadorVoltas = voltasEncoder + 1;
             desliga = true;
             if(desliga == true){
                digitalWrite(rele, LOW);           
              }
            resetar();
            completo();
           }
     
     char tecla_pressionada = teclado1.getKey();  // Localiza a tecla pressionada e adiciona em uma variável
          if(tecla_pressionada){
             if(tecla_pressionada != '*' && tecla_pressionada != '#'){ // Coleta os valores informados pelo Usuário
                valorConfigurado += tecla_pressionada;
                lcd.setCursor(12,0);
                lcd.print(valorConfigurado);
                valorPedido = valorConfigurado.toInt();
                voltasEncoder = valorPedido / centimetrosPorVolta;  // Inicia variáveis de controle

              if(tecla_pressionada == '*'){  // Limpa o valor informado pelo Usuário
                valorConfigurado = "";
                lcd.setCursor(12,0);
                lcd.print("    ");
              }   
       }
}

void interrupcao (){  // Função responsavel pelo controle do motor usando o encoder e o Sensor de Contagem
    cont++;
    
    if(cont == 20){
        contadorVoltas++;
        cont = 0;
     }
}

void resetar(){  // Função responsavel por resetar as variáveis de contrle do sistema 
  valorConfigurado = "";
  valorPedido = 0;
  voltasEncoder = 0;
}

void completo(){  // Função responsavel por reiniciar parcialmente o sistema, não reseta as variáveis de controle dos valores informados pelo usuário   
  delay(1000);
  cont = 0;  
  contadorVoltas = 0;
  valorAtual = 0;
  lcd.clear();
  lcd.print("Finalizado");
  delay(2000);
  lcd.clear();
  lcd.print("Val. Confg: ");
  lcd.setCursor(12,0);
  lcd.print(valorConfigurado);
  lcd.setCursor(0, 1);
  lcd.print("Val. atual: ");
}
