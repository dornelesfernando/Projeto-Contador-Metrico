<h1>Controlando voltas de um motor 2.0</h1>

<p>
Neste exemplo faremos o mesmo teste do sensor de contagem, porém iremos imprimir os valores recebidos em um Lcd 16x2
  
Exemplo:
Usamos um Sensor de Velocidade/Contagem para verificar a quantidade de voltas de um motor, para isso utilizamos um disco encoder preso ao motor para que o sensor possa realizar a leitura.
</p>

<p>Para ligar e desligar o motor utilizamos uma relé controlada por um Push Button</p>

<div></br>
<h2>Conexões:</h2>

Componente --> Arduino
___
 
<h2>Sensor de Velocidade/Contagem</h2>
 
- GND --> GND

- VCC --> 5v

- D0 --> Porta Digital 3

</br><h2>Relé</h2>

- DC+ --> 5v

- DC- --> GND

- IN --> Ligado diretamente ao Push Button
</br>
- NC (Normalmente Fechado) --> Não conectado

- COM (Comum) --> 5v da <strong>fonte de bancada</strong>

- NO (Normalmente Aberto) --> VCC do <strong>motor</strong>

</br><h2>Motor</h2>

- GND --> GND da <strong>fonte de bancada</strong>

- VCC --> NO da <strong>relé</strong>

</br><h2>Botão</h2>
 
- VCC --> 5v
 
- Sinal --> Ligado diretamente ao <strong>IN</strong> da Relé

</br><h2>Lcd 16x2 I2C:</h2>

- GND --> GND

- VCC --> 5v

- SDA --> Porta Analogica A4

- SCL --> Porta Analogica A5
</div>
