# define rele 13  // Relé conectada ao porta 13 do arduino

// Botão liga/pausa
const int botaoLiga = 11;  // Botão conectado a porta 11 do arduino
int statusDoBotaoLiga = 0;  

// Botão desliga/zera
const int botaoDesliga = 12;  // Botão conectado a porta 12 do arduino
int statusDoBotaoDesliga = 0;  

int  led1 = 2, led2 = 5; // Led que irão indicar se o motor está ligado ou desligado


void setup (){
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(rele, OUTPUT);
    pinMode(botaoLiga, INPUT);
    pinMode(botaoDesliga, INPUT);

    Serial.begin(9600);
    Serial.print("Teste Relé");
    Serial.println("");
}

void loop (){
  
    statusDoBotaoLiga = digitalRead(botaoLiga);  
        if (statusDoBotaoLiga == HIGH){  // Relé ligada
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(rele, HIGH);
        Serial.println("Relé Ligada");
        delay(150);
    }

    statusDoBotaoDesliga = digitalRead(botaoDesliga);  
        if (statusDoBotaoDesliga == HIGH){  // Relé Desligada
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(rele, LOW);
        Serial.println("Relé Desligada");
        delay(150);
    }
}
