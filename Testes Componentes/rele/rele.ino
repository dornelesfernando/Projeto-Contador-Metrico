# define rele 13  // Relé conectada ao pino 13 do arduino
const int botao = 2;  // Botão conectado ao pino 2 do arduino
int statusDoBotao = 0;  
int led1 = 3, led2 = 4;  // Led que irão indicar se o motor está ligado ou desligado

void setup (){
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(rele, OUTPUT);
    pinMode(botao, INPUT);
}

void loop (){
  
    statusDoBotao = digitalRead(botao);  
        if (statusDoBotao == HIGH){  // Relé ligada
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(rele, HIGH);
        delay(50);
        digitalWrite(rele, LOW);
    }
        else{  // Relé desligada
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
    }
}
