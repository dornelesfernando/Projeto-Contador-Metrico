<h1>Controlando voltas de um motor</h1>

<p>
Neste exemplo, utilizamos um Sensor de Contagem - Chave Óptica para Encoder de 5mm para monitorar o número de voltas de um motor. Para isso, anexamos um disco encoder ao motor para permitir que o sensor realize as leituras necessárias.</p>

<p>Para controlar a ativação e desativação do motor, utilizamos uma relé acionada por um Push Button</p>
<div>

</br><h1>Lista dos componentes utilizados:</h1>

- 1 Sensor de Contagem - Chave Óptica para Encoder de 5mm
- 1 Disco Encoder
- 1 Relé
- 1 Motor DC
- 1 Push button
</div>

</br><h2>Conexões:</h2>

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

</br><h2>Motor DC</h2>

- GND --> GND da <strong>fonte de bancada</strong>

- VCC --> NO da <strong>relé</strong>

</br><h2>Botão</h2>
 
- VCC --> 5v
 
- Sinal --> Ligado diretamente ao <strong>IN</strong> da Relé
