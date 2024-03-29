﻿# Minesweeper

En el marco de un trabajo practico de la materia Algoritmos y Estructuras de datos I nos fue propuesto implementar una serie de funciones basadas en el famoso juego buscaminas.
En primera instancia tuvimos que hacer la especificacion de cada funcion en logica de primer orden, para luego pasar a su implementacion en C++. Puede encontrarse en el archivo espeficacion.pdf

Cada funcion tiene su respectivo test suite con un cubrimiento de al menos del 95% de las lineas, incluyendo tambien casos borde.

## Tests

Para correr los tests usamos el framework Google Test. Se debe crear una carpeta lib en el proyecto con la libreria para que funcione. La funcion main esta definida de tal forma que se corran todos los tests.

## minasAdyacentes

Como su nombre lo indica, esta funcion se encarga de contar la cantidad de minas adyacentes dado un casillero. Es utilizada luego en otras funciones.

## cambiarBanderita

Dado un casillero, en caso de que no haya una banderita se planta una en el, y en caso de que si haya una banderita se remueve.

## perdio

Dado un tablero y una secuencia de jugadas realizadas, esta funcion devuelve como resultado true en caso de que el jugador haya perdido el juego.

## gano

Dado un tablero y una secuencia de jugadas realizadas, esta funcion devuelve como resultado true en caso de que el jugador haya ganado el juego.

## jugarPlus

Cuando estamos jugando al buscaminas y apretamos una casilla que tiene un camino sin minas a su alrededor este se despeja automaticamente. Esta funcion se encarga de eso.

## sugerirAutomatico121 

En el buscaminas hay un patron llamado 121 que nos permite hacer una jugada con la certeza de que no pisaremos una mina. Dados un tablero, una secuencia de jugadas y una secuencia de banderitas plantadas esta funcion se encarga de sugerirnos una posicion para jugar
de modo que no perdamos, siempre que sea posible encontrar un patron 121 ya sea vertical u horizontal. 

## Autores
- [@fbigiolli](https://github.com/fbigiolli/sistemaVentas)
- [@lucaveron](https://github.com/lucaveron)
- [@winga35](https://github.com/winga35)
- [@juaninaki](https://github.com/juaninaki)
