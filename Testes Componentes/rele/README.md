<h1>Relé e Motor</h1>
<div>
Neste teste, utilizamos um relé para controlar a ativação e desativação de um motor. Além disso, empregamos dois LEDs para indicar visualmente o estado do motor, se está ligado ou desligado.

- Vermelho --> Desligado

- Verde --> Ligado

<div></br>
<h1>Lista dos componentes utilizados:</h1>

- 1 Relé
- 1 Motor DC
- 2 Push button
- 2 Led's (1 verde e 1 vermelho) <strong>Opicional</strong>
- 2 Resistor 470Ω
- 2 Resistor 1kΩ
</div>


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
