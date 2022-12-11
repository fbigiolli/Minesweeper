//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) { //Complejidad Constante.
    int sumaMinas = 0;
    int minaCentral = minaEnPosicion(t,p);
    for (int i = p.first-1; i <= p.first+1 ; ++i) {
        for (int j = p.second-1; j <=p.second+1 ; ++j) { // el doble for siempre recorre 3*3 = 9, por lo que su complejidad es constante.
            pos pCiclo;
            pCiclo.first = i;
            pCiclo.second = j;
            sumaMinas += minaEnPosicion(t,pCiclo);
        }
    }
    return sumaMinas-minaCentral;

    // NOTA: el uso de la funcion auxiliar minaEnPosicion() es por lo menos sospechosa (y dificulta la comprension de lo que estan haciendo). Realmente la necesitan?
    // NOTA: ahi entendi que lo que hacen es sumar las 9 posiciones y restarle 1 si hay una mina. Entiendo que funciona, pero me sigue pareciendo innecesariamente complejo
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) { // Complejidad lineal
    if (contieneBanderita(b,p,t)){
        b.erase(b.begin()+ indice(b,p));
    }
    else if (!contieneJugada(j,t,p)){
        b.push_back(p);
    }
}
/* La complejidad es lineal ya que depende unicamente de la longitud de banderitas. El peor caso es el que
 * recorre banderitas entero y encuentra en la ultima posicion la banderita, ya que vuelve a recorrer la secuencia
 * para encontrar el indice de la banderita. En ese caso tenemos complejidad 2n, siendo n la longitud de banderitas, es decir, lineal.*/

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) { // Complejidad lineal
    bool res = false;
    int i = 0;
    while(i<j.size() && !res) {
        int row = j[i].first.first;
        int col = j[i].first.second;
        if(t[row][col] == true){
            res = true;
        }
        ++i;
    }
    return res;
}

/* Tiene complejidad lineal, ya que la funcion se encarga de recorrer toda la secuencia de jugadas para fijarse si en esa posicion
 * del tablero hay una mina. Por lo tanto, su complejidad depende del largo de jugadas, ya que siempre la recorre entera */

/******++++**************************** EJERCICIO gano ***********+++***********************/
/* la precondicion nos asegura que no hay jugadas repetidas, y que todas las jugadas son validas.
 Por lo tanto, damos por hecho que no hay jugadas repetidas, por lo que para ganar necesitamos
 la misma cantidad de jugadas que de casilleros sin minas en el tablero*/

bool gano(tablero& t, jugadas& j) { // Complejidad n^2 (cuadratica)
    bool res = false;
    int cantidadSinMinas=0;
    for (int i = 0; i < t.size(); ++i) {
        for (int h = 0; h < t[0].size(); ++h) {
            if (t[i][h] == false){
                cantidadSinMinas+=1;
            }
        }
    }
    if (j.size() == cantidadSinMinas && !perdio(t,j)) {
        res = true;
    }
    return res;
}

/* Tiene complejidad cuadratica, ya que para cada fila, itera sobre todas las columnas. De esta forma, itera n columnas
 * por cada n filas, dando como resultado n*n = n^2. (ya que el tablero siempre es cuadrado). No hay peor caso ya que
 * nuestra implentacion recorre el tablero entero siempre para contar la cantidad sin minas. */

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
// O((|j| + |b|)*(|t|^2)) ya que en el peor caso, que es el tablero sin minas, recorreria un cuadrado de
// 3*3 por cada casillero adyacente a lo largo de todo el tablero, y a su vez por cada iteracion recorre la longitud de jugadas y de banderitas.

 void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) { // O((|j| + |b|)*|t|^2))
    if ( t[p.first][p.second]== 1 ){ // si hay una mina la agrega a jugadas y al pisar una mina termina el juego. O(1)
        j.push_back({{p.first,p.second}, minasAdyacentes(t,{p.first,p.second})});
    }
    else if(minasAdyacentes(t,p)>0 && t[p.first][p.second]==0 && !contieneBanderita(b,p,t)){ // O(|b|)
        j.push_back({{p.first,p.second}, minasAdyacentes(t,{p.first,p.second})}); // agrega la posicion a jugadas.
    }
    else{
        if (!contieneJugada(j,t,{p.first,p.second}) && !contieneBanderita(b,p,t) ){ // O(|j|+|b|)
            j.push_back({{p.first,p.second}, minasAdyacentes(t,{p.first,p.second})}); // agrega la posicion a jugadas.
        }
        for (int i = p.first -1; i <= p.first +1 ; ++i) {
            for (int k = p.second-1; k <= p.second +1 ; ++k) { // recorre 3*3
                if (enRango(t,{i,k}) && (i!= p.first || k!= p.second) && !contieneBanderita(b,p,t)){ // O(|b|) no se sale de rango, no considera la posicion central, ya que fue agregada antes.
                    if (t[i][k] == 0 && !contieneJugada(j, t, {i, k}) && !contieneBanderita(b,{i,k},t)) { // O(|j| + |b|)
                        j.push_back({{i, k}, minasAdyacentes(t, {i, k})}); // agrega la posicion a jugadas.
                        if(minasAdyacentes(t, {i, k})==0) {
                            jugarPlus(t, b, {i, k}, j); // recursion sobre la funcion en el caso de que no haya minas adyacentes.
                        }
                    }
                }
            }
        }
    }
}
/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) { // O(|j|^2 + |j| * |b|)
    bool res = false;
    for (int i = 0; i < j.size(); ++i) {
        if (es121Horizontal(t,j,i)) { //recorre longitud de 2 jugada veces en es121Horizontal, las vuelve a recorrer 2 veces mas si se cumple la condicion para chequear los proximos if.
            if (enRango(t,{j[i].first.first - 1, j[i].first.second})&&!(contieneJugada(j, t, {j[i].first.first - 1, j[i].first.second}))&&!(contieneBanderita(b,{j[i].first.first - 1, j[i].first.second},t))) { // por cada iteracion del for volvemos a recorrer toda la secuencia de jugadas.
                p = {j[i].first.first - 1, j[i].first.second};
                res = true;
            }
            if (enRango(t,{j[i].first.first + 1, j[i].first.second})&&!(contieneJugada(j, t, {j[i].first.first + 1, j[i].first.second}))&&!(contieneBanderita(b,{j[i].first.first + 1, j[i].first.second},t))) {
                p = {j[i].first.first + 1, j[i].first.second};
                res = true;
            }
        }

        if (es121Vertical(t,j,i)){ //recorre longitud de 2 jugada veces en es121Vertical, las vuelve a recorrer 2 veces mas si se cumple la condicion para chequear los proximos if.
            if (enRango(t,{j[i].first.first, j[i].first.second - 1})&&!(contieneJugada(j, t, {j[i].first.first, j[i].first.second - 1}))&&!(contieneBanderita(b,{j[i].first.first , j[i].first.second - 1},t))) {
                p = {j[i].first.first, j[i].first.second - 1};
                res= true;
            }
            if (enRango(t,{j[i].first.first, j[i].first.second + 1})&&!(contieneJugada(j, t, {j[i].first.first, j[i].first.second + 1}))&&!(contieneBanderita(b,{j[i].first.first , j[i].first.second + 1},t))) {
                p = {j[i].first.first, j[i].first.second + 1};
                res = true;
            }
        }
    }
    return res;
}

/*En el peor caso de sugerirAutomatico121 nos encontramos que por cada iteracion del for volvemos a recorrer jugadas 8 veces para chequear cada if. Por lo tanto, tenemos complejidad
 * |j|*8(|j| +|b|),  Ya que a su vez, en cada una de las 8 iteraciones recorre tambien la secuencia de banderitas. */
