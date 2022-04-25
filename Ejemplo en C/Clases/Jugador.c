#include "string.h"
#include "stdlib.h"

#include "Jugador.h"
#include "Arma.h"
#include "Pistola.h"
#include "Escopeta.h"
#include "Fusil_Asalto.h"

Lista_Armas *Crear_Lista_Armas(Arma *arma_pistola, Arma *arma_escopeta, Arma *arma_fusil_asalto)
{
    Lista_Armas *nueva_lista_armas = (Lista_Armas *)malloc(sizeof(Lista_Armas));

    nueva_lista_armas->arma_escopeta = NULL;
    nueva_lista_armas->arma_fusil_asalto = NULL;
    nueva_lista_armas->arma_pistola = NULL;

    return nueva_lista_armas;
}
void Destruir_Lista_Armas(Lista_Armas *esta_lista_armas)
{
    free(esta_lista_armas);
}

Jugador *Crear_Jugador(int vida)
{
    Jugador *nuevo_jugador = (Jugador *)malloc(sizeof(Jugador));

    Pistola *nueva_pistola = Crear_Pistola(6, 2.3f, 10);
    Escopeta *nueva_escopeta = Crear_Escopeta(4, 4, 20);
    Fusil_Asalto *nuevo_fusil = Crear_Fusil_Asalto(15, 3.5f, 10);

    Lista_Armas *l_armas = Crear_Lista_Armas(nueva_pistola, nueva_escopeta, nuevo_fusil);

    nuevo_jugador->arma_actual = *l_armas->arma_pistola;
    nuevo_jugador->vida = 30;
    nuevo_jugador->estado_arma = 0;
    nuevo_jugador->tipo_municion = 0;

    return nuevo_jugador;
}
void Destruir_Jugador(Jugador *este_jugador)
{
    free(este_jugador);
}

void Disparar_Arma(Enemigo *objetivo, Arma *arma_actual, Video_Juego *video_juego)
{
    char *l_n_armas[] = {"Pistola", "Escopeta", "Fusil de Asalto"};
    if (objetivo->vida > 0 && arma_actual->municion > 0)
    {
        video_juego->puntos += 5;
        Disparar(objetivo, arma_actual);
        printf("Se diparó el arma: %s", ToString(), "\nPuntos: &d", video_juego->puntos);
    }
    else
    {
        printf("Se diparó el arma: %s", ToString(), "\nPuntos: &d", video_juego->puntos);
    }
}
void Cambiar_Arma(Jugador *ref_jugador, Lista_Armas *l_armas)
{
    char *l_n_armas[3] = {"Pistola", "Escopeta", "Fusil de Asalto"};
    ref_jugador->estado_arma++;
    if (ref_jugador->estado_arma == 1)
    {
        ref_jugador->arma_actual = *l_armas->arma_escopeta;
        printf("Arma actual: %s", l_n_armas[1]);
    }
    else if (ref_jugador->estado_arma == 2)
    {
        ref_jugador->arma_actual = *l_armas->arma_fusil_asalto;
        printf("Arma actual: %s", l_n_armas[1]);
    }
    else if (ref_jugador->estado_arma == 3)
    {
        ref_jugador->estado_arma = 0;
        ref_jugador->arma_actual = *l_armas->arma_pistola;
        printf("Arma actual: %s", l_n_armas[1]);
    }
}
void Recargar_Arma(Jugador *ref_jugador, Arma *arma_actual)
{
    int l_municiones[] = {6, 4, 15};
    char *l_n_armas[] = {"Pistola", "Escopeta", "Fusil de Asalto"};
    if (arma_actual->municion == 0)
    {
        if (ref_jugador->estado_arma == 1)
        {
            ref_jugador->tipo_municion = 1;
            ref_jugador->arma_actual.municion += l_municiones[ref_jugador->tipo_municion];
            printf("Se recargo: %s", l_n_armas[1], "\nMunicion: &d", ref_jugador->arma_actual.municion);
        }
        else if (ref_jugador->estado_arma == 2)
        {
            ref_jugador->tipo_municion = 2;
            ref_jugador->arma_actual.municion += l_municiones[ref_jugador->tipo_municion];
            printf("Se recargo: %s", l_n_armas[2], "\nMunicion: &d", ref_jugador->arma_actual.municion);
        }
        else if (ref_jugador->estado_arma == 3)
        {
            ref_jugador->tipo_municion = 0;
            ref_jugador->arma_actual.municion += l_municiones[ref_jugador->tipo_municion];
            printf("Se recargo: %s", l_n_armas[0], "\nMunicion: &d", ref_jugador->arma_actual.municion);
        }
        else
            printf("Ocurrio un error");
    }
}