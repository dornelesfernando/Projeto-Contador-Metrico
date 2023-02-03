<h1>Automatizando voltas de um motor</h1>

<p>
Neste exemplo usamos um Sensor de Velocidade/Contagem para verificar a quantidade de voltas de um motor utilizando um encoder, após o usuário informar manualmente no código a quantidade de voltas que deseja que o motor de, um relé será ativado e fará essa quantia de voltas informadas pelo usuário.
</p>

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

</br><h2>Lcd 16x2 I2C:</h2>

- GND --> GND

- VCC --> 5v

- SDA --> Porta Analogica A4

- SCL --> Porta Analogica A5
</div>
