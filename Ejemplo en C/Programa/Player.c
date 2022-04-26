#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Player.h"
#include "VideoJuego.h"
#include "Enemigo.h"

#include "Pistola.h"
#include "Escopeta.h"
#include "Fusil.h"

Player *Crear_Jugador()
{
    Player *nuevo_jugador = (Player *)malloc(sizeof(Player));

    for (int i = 0; i < 3; i++)
    {
        nuevo_jugador->l_armas[i] = (Gun *)malloc(sizeof(Gun));
    }

    nuevo_jugador->l_armas[1] = (Gun *)malloc(sizeof(Gun));
    nuevo_jugador->l_armas[2] = (Gun *)malloc(sizeof(Gun));

    nuevo_jugador->vida = 30;
    nuevo_jugador->estado_arma = 0;
    nuevo_jugador->tipo_municion = 0;

    Pistola *nueva_pistola = Crear_Pistola(6, 2.1f, 10);
    Escopeta *nueva_escopeta = Crear_Escopeta(4, 4.5f, 10);
    Fusil *nuevo_fusil = Crear_Fusil_Asalto(15, 3.5f, 10);

    nuevo_jugador->l_armas[0] = (Gun *)nueva_pistola;
    nuevo_jugador->l_armas[1] = (Gun *)nueva_escopeta;
    nuevo_jugador->l_armas[2] = (Gun *)nuevo_fusil;

    nuevo_jugador->arma_actual = nuevo_jugador->l_armas[0];

    return nuevo_jugador;
}
void Destruir_Jugador(Player *este_jugador)
{
    free(este_jugador);
}

void Disparar_Arma(Player *este_jugador, void *este_objetivo, void *este_video_juego)
{
    Enemigo *ref_enemigo = (Enemigo*)este_objetivo;
    VideoJuego *ref_video_juego = (VideoJuego*) este_video_juego; 

    if (ref_enemigo->vida > 0 && este_jugador->arma_actual->municion > 0)
    {
        ref_video_juego->puntos += 5;
        Disparar((Gun *)este_jugador->arma_actual, este_objetivo);

        printf("Se disparo el arma : ");
        Nombre_Arma((Gun *)este_jugador->arma_actual);
        printf("Puntos: %i \n", ref_video_juego->puntos);
    }
    else
    {
        printf("No se disparo el arma : ");
        Nombre_Arma((Gun *)este_jugador->arma_actual);
        printf("Puntos: %i \n", ref_video_juego->puntos);
    }
}

void Cambiar_Arma(Player *este_jugador)
{
    este_jugador->estado_arma++;
    este_jugador->arma_actual = este_jugador->l_armas[este_jugador->estado_arma];
    if (este_jugador->estado_arma == 2)
    {
        este_jugador->estado_arma = -1;
    }
    printf("Arma Actual: ");
    Nombre_Arma((Gun *)este_jugador->arma_actual);
}

void Recargar_Arma(Player *este_jugador)
{
    int l_municiones[] = {6, 4, 15};
    char *l_nombres_armas[] = {"Pistola", "Escopeta", "Fusil de Asalto"};
    if (este_jugador->arma_actual->municion == 0)
    {
        if (este_jugador->estado_arma == 0)
        {
            este_jugador->tipo_municion = 0;
            este_jugador->arma_actual->municion += l_municiones[este_jugador->tipo_municion];
            printf("Se recargo la: %s /nMunicion: %i", l_nombres_armas[0], este_jugador->arma_actual->municion);
        }
        else if (este_jugador->estado_arma == 1)
        {
            este_jugador->tipo_municion = 1;
            este_jugador->arma_actual->municion += l_municiones[este_jugador->tipo_municion];
            printf("Se recargo la: %s /nMunicion: %i", l_nombres_armas[1], este_jugador->arma_actual->municion);
        }
        else if (este_jugador->estado_arma == 2)
        {
            este_jugador->tipo_municion = 2;
            este_jugador->arma_actual->municion += l_municiones[este_jugador->tipo_municion];
            printf("Se recargo el: %s /nMunicion: %i", l_nombres_armas[2], este_jugador->arma_actual->municion);
        }
        else
        {
            printf("Ocurrio un error");
        }
    }
}