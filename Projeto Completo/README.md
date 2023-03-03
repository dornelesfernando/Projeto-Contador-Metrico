<h1>Contador Métrico</h1>

<i>Este projeto tem como objetivo desenvolver um sistema automatizado que mede a quantidade de fita, fio ou outros materiais que um motor é capaz de enrolar. Para isso, 
busca-se criar uma solução que possa detectar o movimento do motor e calcular a quantidade de produto processado de forma precisa e confiável. A utilização dessa 
ferramenta visa simplificar e otimizar processos que dependem da contagem manual desses materiais, proporcionando uma solução mais eficiente e precisa.</i>

<div>
Para alcançar esse objetivo, utilizaremos um Teclado Matricial para que o usuário possa definir a quantidade do material que deseja que o motor enrole. Além disso, um 
Display será utilizado para apresentação dos dados ao usuário, uma Relé para acionamento do motor e um Sensor de Contagem - Chave Óptica para Encoder 5mm e um Encoder 
serão utilizados como forma de controle para desligar o motor.

Cada volta do disco do encoder representa uma determinada quantidade de fita enrolada, representada pela variável "X" em centímetros. A variável "Quantidade_Desejada", 
também em centímetros, representa a quantidade de fita que o usuário deseja que o motor enrole. Com base nesses dados, é possível calcular a quantidade de voltas 
necessárias para atingir a quantidade desejada de fita, utilizando a fórmula "Voltas = X". Em seguida, a quantidade total de voltas necessárias para atingir a quantidade 
desejada de fita pode ser calculada utilizando a fórmula "voltas_totais = Quantidade_Desejada / voltas". Dessa forma, será possível contabilizar de forma precisa e 
eficiente a quantidade de fita enrolada pelo motor.

Com este projeto, espera-se proporcionar uma solução automatizada e eficiente para a medição de materiais enrolados pelo motor, que pode ser aplicada em diversos 
processos industriais.

</div>
  
<div> </br>
<h2>Lista dos materiais utilizados neste projeto:</h2>

- 1 Teclado Matricial 3x4 de 12 teclas rígido
- 1 Display LCD 16x2 com comunicação I2C
- 1 Módulo Relé de 5V e 10A com 1 canal
- 1 Sensor de Contagem - Chave Óptica para Encoder de 5mm
- 1 Disco Encoder 5mm
- 1 Motor Dc
- 2 Push Button
- 2 Resistores de 1kΩ
</div>

<h2>Conexões:</h2>

Componente --> Arduino
___
 
<h2>Teclado Matricial 3x4 de 12 teclas rígido</h2>

- Pino 1 --> Não conectado
- Pino 2 --> Porta 9
- Pino 3 --> Porta 4
- Pino 4 --> Porta 10
- Pino 5 --> Porta 7
- Pino 6 --> Porta 8
- Pino 7 --> Porta 6
- Pino 8 --> Porta 5
- Pino 9 --> Não conectado
 
</br><h2>Lcd 16x2 I2C:</h2>

- GND --> GND

- VCC --> 5v

- SDA --> Porta Analogica A4

- SCL --> Porta Analogica A5
 
 </br><h2>Relé</h2>

- DC+ --> 5v

- DC- --> GND

- IN --> Pino 13 
</br>
- NC (Normalmente Fechado) --> Não conectado

- COM (Comum) --> 5v (ou Voltangem necessária para usar o motor) da <strong>fonte de bancada</strong>

- NO (Normalmente Aberto) --> VCC do <strong>motor</strong>

</br><h2>Motor</h2>

- GND --> GND da <strong>fonte de bancada</strong>

- VCC --> NO da <strong>relé</strong>
 
</br><h2>Sensor de Contagem - Chave Óptica para Encoder de 5mm</h2>
 
- GND --> GND

- VCC --> 5v

- D0 --> Porta Digital 3

</br><h2>Push Button 1</h2>
 
- VCC --> 5v

- GND --> GND ligado a um resitor de <strong>1KΩ</strong> realizando um <strong>pull-down</strong>

- Sinal --> Porta 11

</br><h2>Push Button 2</h2>
 
- VCC --> 5v
 
- GND --> GND ligado a um resitor de <strong>1KΩ</strong> realizando um <strong>pull-down</strong>
 
- Sinal --> Porta 12
</div>
