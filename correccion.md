# Hello World

## Notas/Comentarios

- los tests entregados tienen la cobertura requerida (e hicieron una buena cantidad de tests :)
- fallan 5 tests de la catedra:
```
[  FAILED  ] 5 tests, listed below:
[  FAILED  ] cambiarBanderitaTEST.cambiarBanderitaEnPosicionYaJugada
[  FAILED  ] jugarPlusTEST.noSePuedeJugarSobreBanderita
[  FAILED  ] jugarPlusTEST.juegoSobreUnaMina
[  FAILED  ] sugerirAutomatico121TEST.sugerenciaValida121VerticalBorde
[  FAILED  ] sugerirAutomatico121TEST.sugerencia2Validas121VerticalBordeConBanderita
```
- las respuestas a las preguntas de complejidad no son correctas. No me queda claro porque querrian iterar sobre la matriz de jugadas. Fijense si al cambiar la secuencia por matriz no hay cosas que se les hacen mas faciles/rapidas
- no detallan la complejidad de las funciones auxiliares. Asumo que las calcularon, ya que de otra forma no podrian haber calculado la de las funciones que las llamand, pero hubiera sido util anotarlas en el codigo
- mencionan que la complejidad de `jugarPlus()` es `9*(|j|+|b|)^(|t|^2)`, lo cual es exponencial en el tama~no de la matriz. Si es asi, entonces tienen que cambiar la implementacion a otra mas eficiente (con menor complejidad)
- vean los comentarios en el codigo que dicen "//NOTA:"

## Nota

Re-entregar