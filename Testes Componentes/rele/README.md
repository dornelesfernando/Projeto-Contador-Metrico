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

___

<h2>Relé</h2>

- DC+ --> 5v

- DC- --> GND

- IN --> Porta 13

___

- NC (Normalmente Fechado) --> Não conectado

- COM (Comum) --> 5v da <strong>fonte de bancada</strong>

- NO (Normalmente Aberto) --> VCC do <strong>motor</strong>


</br><h2>Botão1</h2>

- GND --> GND ligado a um resitor de <strong>1KΩ</strong> realizando um <strong>pull-down</strong>

- VCC --> 5v

- Sinal --> Porta 11 

</br><h2>Botão2</h2>

- GND --> GND ligado a um resitor de <strong>1KΩ</strong> realizando um <strong>pull-down</strong>

- VCC --> 5v

- Sinal --> Porta 12


</br><h2>Motor</h2>

- GND --> GND da <strong>fonte de bancada</strong>

- VCC --> NO da <strong>relé</strong>


</br><h2>Led Vermelho</h2>

- GND --> GND

- VCC --> Porta 2 ligado a um resitor de <strong>470Ω</strong>

</br><h2>Led Verde</h2>

GND --> GND

VCC --> Porta 5 ligado a um resitor de <strong>470Ω</strong>
</div>
