<h1>Relé e Motor</h1>
<div>
Neste teste usamos uma relé para ligar e desligar um motor, além disso usamos 2 (dois) led's para indicar se o motor está ligado ou desligado.

- Vermelho --> Desligado

- Verde --> Ligado

<div></br>
<h1>Componentes usados</h1>

- 1 Protoboard
- 1 Relé
- 1 Push button
- 1 Motor DC
- 2 Led's (1 verde e 1 vermelho) <strong>Opicional</strong></div>

<div></br>
<h1>Conexões no arduino</h1>

<strong>Componente --> Arduino</strong>


</br><h2>Relé</h2>

<h3>DC+ --> 5v</h3>
<h3>DC- --> GND</h3>
<h3>IN --> Pino 13</h3>
</br>
<h3>NC (Normalmente Fechado) --> Não conectado</h3>
<h3>COM (Comum) --> 5v da <strong>fonte de bancada</strong></h3>
<h3>NO (Normalmente Aberto) --> VCC do <strong>motor</strong></h3>

____

<h2>Botão</h2>

<h3>GND --> GND ligado a um resitor de <strong>1KΩ</strong> realizando um <strong>pull-down</strong></h3>
<h3>VCC --> 5v</h3>
<h3>Sinal --> Pino 2</h3>

____

<h2>Motor</h2>
<h3>GND --> GND da <strong>fonte de bancada</strong></h3>
<h3>VCC --> NO da <strong>relé</strong></h3>

____

<h2>Led Vermelho</h2>
<h3>GND --> GND</h3>
<h3>VCC --> Pino 3 ligado a um resitor de <strong>470Ω</strong></h3>

____

<h2>Led Verde</h2>
<h3>GND --> GND </h3>
<h3>VCC --> Pino 4 ligado a um resitor de <strong>470Ω</strong></h3>
</div>