#ifndef _ENEMIGO_H
#define _ENEMIGO_H

#include "Machete.h"
#include "Jugador.h"

typedef struct _enemigo
{
    int vida;
    Machete arma;

} Enemigo;

Enemigo *Crear_Enemigo(int vida);
void Destruir_Enemigo(Enemigo *este_enemigo, Machete *este_machete);
void Lanzar_Machete(Jugador *objetivo);

#endif