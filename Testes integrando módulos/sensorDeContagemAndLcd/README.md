<h1>Controlando voltas de um motor 2.0</h1>

<p>
Neste exemplo, utilizaremos novamente o sensor de contagem, que consiste em uma chave óptica conectada a um encoder de 5mm. Utilizaremos um disco encoder preso ao motor para que o sensor possa realizar a leitura da quantidade de voltas. Ao invés de apenas verificar a quantidade de voltas do motor, o valor recebido pelo sensor será impresso em um display LCD 16x2, permitindo que o usuário possa visualizar a informação de forma clara e precisa.
</p>

<p>Para ligar e desligar o motor utilizamos uma relé controlada por um Push Button</p>

<div> </br>
<h2>Lista dos materiais utilizados neste projeto:</h2>

- 1 Display LCD 16x2 com comunicação I2C
- 1 Módulo Relé de 5V e 10A com 1 canal
- 1 Sensor de Contagem - Chave Óptica para Encoder de 5mm
- 1 Disco Encoder 5mm
- 1 Motor Dc
- 1 Push Button
</div>

<div></br>
<h2>Conexões:</h2>

Componente --> Arduino
___
 
<h2>Sensor de Contagem - Chave Óptica para Encoder de 5mm</h2>
 
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
