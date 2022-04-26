#ifndef _VIDEOJUEGO_H_
#define _VIDEOJUEGO_H_

#include "stdbool.h"
#include "Player.h"

typedef struct _videojuego{
    Player *soldado;
    int puntos;
} VideoJuego;

VideoJuego *Crear_Video_Juego();
void Destruir_Video_Juego(VideoJuego *este_video_juego);

bool Ganador(VideoJuego *este_video_juego);
bool Perdedor(VideoJuego *este_video_juego);

#endif