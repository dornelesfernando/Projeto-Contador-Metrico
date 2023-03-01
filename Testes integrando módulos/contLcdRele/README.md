<h1>Automatizando voltas de um motor</h1>

<p>
Neste exemplo usamos um Sensor de Contagem - Chave Óptica para Encoder de 5mm para verificar a quantidade de voltas de um motor utilizando um encoder, após o usuário informar manualmente no código a quantidade de voltas que deseja que o motor de, um relé será ativado e fará essa quantia de voltas informadas pelo usuário.
</p></br>

<div> </br>
<h2>Lista dos materiais utilizados neste projeto:</h2>

- 1 Display LCD 16x2 com comunicação I2C
- 1 Módulo Relé de 5V e 10A com 1 canal
- 1 Sensor de Contagem - Chave Óptica para Encoder de 5mm
- 1 Disco Encoder 5mm
- 1 Motor Dc
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

- IN --> Pino 13
</br>

- NC (Normalmente Fechado) --> Não conectado

- COM (Comum) --> 5v da <strong>fonte de bancada</strong>

- NO (Normalmente Aberto) --> VCC do <strong>motor</strong>

</br><h2>Motor</h2>

- GND --> GND da <strong>fonte de bancada</strong>

- VCC --> NO da <strong>relé</strong>

</br><h2>Lcd 16x2 I2C:</h2>

- GND --> GND

- VCC --> 5v

- SDA --> Porta Analogica A4

- SCL --> Porta Analogica A5
</div>
