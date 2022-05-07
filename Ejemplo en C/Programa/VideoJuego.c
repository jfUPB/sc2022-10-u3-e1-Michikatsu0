#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "VideoJuego.h"

VideoJuego *Crear_Video_Juego()
{
    VideoJuego *nuevo_video_juevo = (VideoJuego*)malloc(sizeof(VideoJuego));

    nuevo_video_juevo->soldado = Crear_Jugador();
    nuevo_video_juevo->puntos = 0;

    return nuevo_video_juevo;
}
void Destruir_Video_Juego(VideoJuego *este_video_juego)
{
    free(este_video_juego);
}

bool Ganador(VideoJuego *este_video_juego)
{
    if (este_video_juego->puntos >= 100)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Perdedor(VideoJuego *este_video_juego)
{
    if (este_video_juego->soldado->vida <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}