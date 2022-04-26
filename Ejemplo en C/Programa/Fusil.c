#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Fusil.h"
#include "Enemigo.h"

void __Nombre_Arma_Fusil()
{
    printf("Fusil de Asalto");
}

void __Disparar_Fusil(void *esta_arma, void *este_enemigo){
    Gun *ref_arma = (Gun*) esta_arma;
    Enemigo *ref_enemigo = (Enemigo*) este_enemigo;
    if (ref_enemigo->vida > 0)
    {
        if (ref_enemigo->vida <= 0){
            ref_enemigo->vida = 0;
            printf("No se pudo disparar el Fusil de Asalto, el Enemigo ya esta muerto.\nVida del objetivo: %d \nMunicion: %d", ref_enemigo->vida, ref_arma->municion);
        }
        else
        {
            ref_enemigo->vida -= 2;
            ref_arma->municion -= 2;
            printf("Se disparo el Fusil de Asalto.\nVida del objetivo: %d \nMunicion: %d", ref_enemigo->vida, ref_arma->municion);
        }
    }
    else if (ref_arma->municion <= 0)
    {
        printf("No se pudo disparar el Fusil de Asalto. Sin municion: %d", ref_arma->municion);
    }
    else
    {
        printf("Ocurrio un error");
    }
}

Fusil *Crear_Fusil_Asalto(int municion, float tiempo_recarga, int dano)
{
    Fusil *nuevo_fusil = (Fusil*) malloc(sizeof(Fusil));

    nuevo_fusil->arma = *Crear_Arma(municion, tiempo_recarga, dano);
    nuevo_fusil->arma.disparar_func = __Disparar_Fusil;
    nuevo_fusil->arma.nombre_func = __Nombre_Arma_Fusil;
    nuevo_fusil->cargador_ampliado = 3;

    nuevo_fusil->arma.municion *= nuevo_fusil->cargador_ampliado;

    return nuevo_fusil;
}
void Destruir_Fusil_Asalto(Fusil *este_fusil_asalto)
{
    Destruir_Arma((Gun*)este_fusil_asalto);
}
