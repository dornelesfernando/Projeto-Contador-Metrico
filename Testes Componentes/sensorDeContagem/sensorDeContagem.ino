volatile int cont = 0;
int volta = 0;

void setup(){
    pinMode(3, INPUT);
    attachInterrupt(digitalPinToInterrupt(3), interrupcao, RISING);

    Serial.begin(9600);
    Serial.println("Contagem iniciada");
}

void loop (){
    delay(1000);
    Serial.print("Quantidade de voltas:");
    Serial.println(volta);
    Serial.print("Quantidade de furos:");
    Serial.println(cont);
}

void interrupcao (){
    cont++;
    
    if(cont == 20){
        volta++;
        cont = 0;
      }
}
