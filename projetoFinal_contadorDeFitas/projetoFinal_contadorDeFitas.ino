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

// Botão Liga
const int botaoLiga = 11;  // Botão conectado ao pino 11 do arduino
int statusDoBotaoLiga = 0; 

// Botão Pausa
const int botaoPausa = 12;  // Botão conectado ao pino 12 do arduino
int statusDoBotaoPausa = 0;

// Variáveis gerais
int valorPedido = 0;  // Armazena o valor informado pelo usuário
float centimetrosPorCont = 0.5;  // Alterar para o valor em centimetros que seu motor faz por volta ***********
int qtdEncoder = 0;  // Armazena a quantidade de voltas que o motor terá que dar para satisfazer o pedido do usuário
int valorAtual = 0;  // Monitora a distância já percorrida
static String valorConfigurado = "";
int contAux = 0;

// Variáveis de controle para o Monitor serial
int i = 0;
int p = 0;

void setup(){    
    pinMode(rele, OUTPUT);
    pinMode(3, INPUT);
    pinMode(botaoLiga, INPUT);
    pinMode(botaoPausa, INPUT);
        attachInterrupt(digitalPinToInterrupt(3), interrupcao, CHANGE);
    lcd.init();  // Inicializa o lcd
    lcd.backlight();  // Liga a Luz de Fundo
    lcd.print("Tamanho:      Cm");
    lcd.setCursor(0, 1);
    lcd.print("Medicao:      Cm");  
        Serial.begin(9600);  // Inicia a Serial
        Serial.println("Sistema iniciado"); 
        Serial.println();        
}

void loop(){
  statusDoBotaoLiga = digitalRead(botaoLiga);
  if(statusDoBotaoLiga == HIGH){  // Se o botão iniciar for apertado 
     Serial.println("Botão iniciar pressionado");
     if(valorPedido != 0){
      cont = contAux;
     for(cont; cont <= qtdEncoder;){ 
         statusDoBotaoPausa = digitalRead(botaoPausa); 
         char tecla_pressionada = teclado1.getKey();
         
            
         if(tecla_pressionada == '#'){
            Serial.println("Botão finalizar pressionado, para resetar pressione novamente");         
            return;                   
            } 
         if(statusDoBotaoPausa == HIGH){  // Se o botão pausar for pressionado
            Serial.println("Botão pause pressionado");
            Serial.println("Relé desligada");
            Serial.println();
            return;
           }

         digitalWrite(rele, HIGH);  // Liga relé
         valorAtual = cont * centimetrosPorCont;  // Inicia/atualiza a variável de controle    
         lcd.setCursor(9, 1);
         lcd.print(valorAtual);  // Mostra no Lcd

              Serial.print("valorPedido ");
     Serial.println(valorPedido);
     Serial.print("valorConfigurado ");
     Serial.println(valorConfigurado);
     Serial.print("qtdEncoder ");
     Serial.println(qtdEncoder);
     Serial.print("cont ");
     Serial.println(cont);
     Serial.print("i ");
     Serial.println(i);
     Serial.print("p ");
     Serial.println(p);
     Serial.println();
         
         for(i; i < 1; i++){ // Imprime apenas uma vez na Serial
             Serial.println("Relé iniciada");
             Serial.println();
            }
                contAux = cont;                   
         }
     digitalWrite(rele, LOW);  // Desliga relé
     lcd.clear();
     lcd.print("Finalizado");
     delay(2000);
     completo();  // Reinicia parcialmente o sistema, não reseta as variáveis de controle dos valores informados pelo usuário   
     Serial.println("Relé desligada");
     Serial.println("Finalizado");
     Serial.println(); Serial.println();
    }
  }
  else{
      digitalWrite(rele, LOW);  // Caso o botão iniciar não seja apertado a relé permanece desligada  
     }
     
  char tecla_pressionada = teclado1.getKey();  // Localiza a tecla pressionada e adiciona em uma variável
  if(tecla_pressionada){
     if(tecla_pressionada != '*' && tecla_pressionada != '#'){  // Coleta os valores informados pelo Usuário
        if(valorConfigurado.length() < 5){
          valorConfigurado += tecla_pressionada;
        }
        lcd.setCursor(9, 0);
        lcd.print(valorConfigurado);
        valorPedido = valorConfigurado.toInt();
        qtdEncoder = valorPedido / centimetrosPorCont;  // Inicia variáveis de controle
       }
        for(p; p < 1; p++){  // Imprime apenas uma vez na Serial
            Serial.println("O usuário indicou um valor");
          }
     if(tecla_pressionada == '*'){  // Limpa o valor informado pelo Usuário
        Serial.println("Valor indicado pelo usuário resetado");
        Serial.println();
        p = 0;  // reseta a variável responsavel pelo controle de uma informação no serial monitor
        valorConfigurado = "";
        valorPedido = 0;
        qtdEncoder = 0;
        lcd.setCursor(0, 0);
        lcd.print("Tamanho:      Cm");
       }
     if(tecla_pressionada == '#'){
        cont = qtdEncoder + 1;
        digitalWrite(rele, LOW);                       
        resetar();
        completo();
      } 
   }             
}

void interrupcao (){  // Função responsavel pelo controle do motor usando o encoder e o Sensor de Contagem
    cont++;
}

void resetar(){  // Função responsavel por resetar as variáveis de contrle do sistema 
  valorConfigurado = "";
  valorPedido = 0;
  qtdEncoder = 0;
  lcd.clear();
  lcd.print("Resetado");
  delay(1000);
  cont = 0;
}

void completo(){  // Função responsavel por reiniciar parcialmente o sistema, não reseta as variáveis de controle dos valores informados pelo usuário   
  i = 0;
  p = 0;
  cont = 0;  
  contAux = 0;
  valorAtual = 0;
  delay(1000);
  lcd.clear();
  lcd.print("Tamanho:      Cm");
  lcd.setCursor(0, 1);
  lcd.print("Medicao:      Cm");
  lcd.setCursor(9,0);
  lcd.print(valorConfigurado);
}
