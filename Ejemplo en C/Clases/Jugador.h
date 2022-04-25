#ifndef _JUGADOR_H
#define _JUGADOR_H

#include "Arma.h"
#include "Video_Juego.h"
#include "Enemigo.h"

typedef struct _lista_armas{
    Arma *arma_pistola;
    Arma *arma_escopeta;
    Arma *arma_fusil_asalto; 
} Lista_Armas;

Lista_Armas *Crear_Lista_Armas(Arma *arma_pistola, Arma *arma_escopeta, Arma *arma_fusil_asalto);
void Destruir_Lista_Armas(Lista_Armas *esta_lista_armas);

typedef struct _jugador // 
{
    int vida;
    Lista_Armas l_armas;
    Arma arma_actual;
    int estado_arma;
    int tipo_municion;
} Jugador;


Jugador *Crear_Jugador(int vida);
void Destruir_Jugador(Jugador *este_jugador);


void Disparar_Arma(Enemigo *objetivo, Arma *arma_actual, Video_Juego *video_juego);
void Cambiar_Arma(Jugador *ref_jugador, Lista_Armas *l_armas);
void Recargar_Arma(Jugador *ref_jugador, Arma *arma_actual);

#endif