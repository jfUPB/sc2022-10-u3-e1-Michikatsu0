#ifndef _PLAYER_H
#define _PLAYER_H

#include "Gun.h"

typedef struct _player
{
    int vida;
    Gun *l_armas[3];
    Gun *arma_actual;
    int estado_arma;
    int tipo_municion;
    
} Player;

Player *Crear_Jugador();
void Destruir_Jugador(Player *este_jugador);

void Disparar_Arma(Player *este_jugador, void *este_objetivo, void *este_video_juego);
void Cambiar_Arma(Player *este_jugador);
void Recargar_Arma(Player *este_jugador);

#endif