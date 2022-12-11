
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

int minaEnPosicion(tablero t, pos p);
int indice(banderitas b,pos x);
bool contieneJugada(jugadas j,tablero t,pos p);
bool contieneBanderita(banderitas b,pos p,tablero& t);
bool es121Horizontal(tablero& t, jugadas& j, int i);
bool es121Vertical(tablero& t, jugadas& j, int i);
bool enRango(tablero t, pos p);