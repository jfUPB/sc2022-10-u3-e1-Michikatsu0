#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Pistola.h"
#include "Enemigo.h"

void __Nombre_Arma_Pistola()
{
    printf("Pistola");
}

void __Disparar_Pistola(void *esta_arma, void *este_enemigo){
    Gun *ref_arma = (Gun*) esta_arma;
    Enemigo *ref_enemigo = (Enemigo*) este_enemigo;
    if (ref_enemigo->vida > 0)
    {
        if (ref_enemigo->vida <= 0){
            ref_enemigo->vida = 0;
            printf("No se pudo disparar el Pistola, el Enemigo ya esta muerto.\nVida del objetivo: %d \nMunicion: %d", ref_enemigo->vida, ref_arma->municion);
        }
        else
        {
            ref_enemigo->vida -= 2;
            ref_arma->municion -= 2;
            printf("Se disparo el Pistola.\nVida del objetivo: %d \nMunicion: %d", ref_enemigo->vida, ref_arma->municion);
        }
        
    }
    else if (ref_arma->municion <= 0)
    {
        printf("No se pudo disparar el Pistola. Sin municion: %d", ref_arma->municion);
    }
    else
    {
        printf("Ocurrio un error");
    }
}

Pistola *Crear_Pistola(int municion, float tiempo_recarga, int dano)
{
    Pistola *nueva_pistola = (Pistola*)malloc(sizeof(Pistola));

    nueva_pistola->arma = *Crear_Arma(municion,tiempo_recarga,dano);
    nueva_pistola->arma.disparar_func = __Disparar_Pistola;
    nueva_pistola->arma.nombre_func = __Nombre_Arma_Pistola;
    nueva_pistola->cargador_rapido = 1.5f;

    nueva_pistola->arma.tiempo_recarga -= nueva_pistola->cargador_rapido;

    return nueva_pistola;
}

void Destruir_Pistola(Pistola *esta_pistola)
{
    Destruir_Arma((Gun*)esta_pistola);
}