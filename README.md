<h1>Contador de fitas</h1>

<h3>Esse projeto consiste em crir uma forma de contabilizar o quanto um motor enrola de fita de uma maneira 
automatica.</h3>

<div>
Para esse projeto usaremos um Teclado Matricial onde o usuario indicara o quanto de fita quer que o motor enrrole; um display onde os dados serão apresentados para o usuario; uma relé que indicará quando o motor deverá funcionar e por fim um Sensor de Contagem - Chave Óptica para Encoder 5mm e um Encoder que serão usados como forma de controle para desligar o motor.

A cada volta do disco encoder temos certa quantia de fita enrrolada.

Sendo <strong>"X"</strong> um valor em <strong>Cm</strong> de fita que o motor enrrola durante 1 (uma) volta e a variável <strong>"Quantidade_Desejada"</strong> um valor em <strong>Cm</strong>, temos:

Voltas = X  
voltas_totais = Quantidade_Desejada / voltas
</div>
  
<div> </br>
<h2>Materiais usados:</h2>

- 1 Protoboard 
- 1 Teclado Matricial 3x4 12 Teclas Rígido
- 1 Display LCD 16x2 I2C
- 1 Relé Módulo Relé 5V 10A 1 Canal
- 1 Sensor de Contagem - Chave Óptica para Encoder 5mm
- 1 Disco Encoder
- 1 Motor 
</div>
