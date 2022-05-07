#ifndef _ENEMIGO_H
#define _ENEMIGO_H

#include "Machete.h"
#include "Player.h"

typedef struct _enemigo
{
    int vida;
    Machete *arma;

} Enemigo;

Enemigo *Crear_Enemigo(int vida);
void Destruir_Enemigo(Enemigo *este_enemigo);
void Lanzar_Machete(Enemigo *este_enemigo, void *este_jugador);

#endif