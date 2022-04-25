#ifndef _VIDEO_JUEGO_H
#define _VIDEO_JUEGO_H

#include "Jugador.h"
#include "Enemigo.h"
#include <stdbool.h>

typedef struct _lista_enemigos // es una lista que "simula la biblioteca List<> de C#"
{
    //la lista esta compuesta de nodos que son el enemigo y el siguiente nodo que contiene otro enemigo
    Enemigo zombie;
    Lista_Enemigos *siguiente_enemigo;
    
} Lista_Enemigos;


typedef struct _Video_Juego
{
    Jugador soldado;
    // lista de enemigos
    int puntos; 

} Video_Juego;






Video_Juego* Crear_Video_Juego(Jugador* soldado);

bool *Ganador();
bool *Perdedor();

#endif