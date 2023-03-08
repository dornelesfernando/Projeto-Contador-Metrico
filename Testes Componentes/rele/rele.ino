# define rele 13  // Relé conectada ao porta 13 do arduino

// Botão liga/pausa
const int botaoLiga = 11;  // Botão conectado a porta 11 do arduino
int statusDoBotaoLiga = 0;  

// Botão desliga/zera
const int botaoDesliga = 12;  // Botão conectado a porta 12 do arduino
int statusDoBotaoDesliga = 0;  

int  ledVemelho = 2, ledVerde = 5; // Led que irão indicar se o motor está ligado ou desligado


void setup (){
    pinMode(ledVemelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(rele, OUTPUT);
    pinMode(botaoLiga, INPUT);
    pinMode(botaoDesliga, INPUT);

    Serial.begin(9600);
    Serial.println("Teste Relé");
    Serial.println("-----------------");

    digitalWrite(ledVemelho, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(rele, LOW);
}

void loop (){
    statusDoBotaoLiga = digitalRead(botaoLiga);  
    statusDoBotaoDesliga = digitalRead(botaoDesliga);
        if (statusDoBotaoLiga == HIGH){  // Relé ligada
        digitalWrite(ledVemelho, LOW);
        digitalWrite(ledVerde, HIGH);
        digitalWrite(rele, HIGH);
        Serial.println("- Relé Ligada");
        Serial.println();
        delay(150);
    }  
        if (statusDoBotaoDesliga == HIGH){  // Relé Desligada
        digitalWrite(ledVemelho, HIGH);
        digitalWrite(ledVerde, LOW);
        digitalWrite(rele, LOW);
        Serial.println("Relé Desligada");
        Serial.println();
        delay(150);
    }
}
