#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Escopeta.h" 


void __Nombre_Arma_Pistola()
{
    printf("Pistola");
}

void __Disparar_Escopeta(void *esta_arma, void *este_enemigo)
{
    Gun *ref_arma = (Gun*) esta_arma;
    Enemigo *ref_enemigo = (Enemigo*) este_enemigo;
    if (ref_enemigo->vida > 0)
    {
        if (ref_enemigo->vida <= 0){
            ref_enemigo->vida = 0;
            printf("No se pudo disparar la Escopeta, el Enemigo ya esta muerto.\nVida del objetivo: %i \nMunicion: %i", ref_enemigo->vida, ref_arma->municion);

        }
        else
        {
            ref_enemigo->vida -= 2;
            ref_arma->municion -= 2;
        }
        printf("Se disparo la Escopeta.\nVida del objetivo: %i \nMunicion: %i", ref_enemigo->vida, ref_arma->municion);
    }
    else if (ref_arma->municion <= 0)
    {
        printf("No se pudo disparar la Escopeta. Sin municion: %i", ref_arma->municion);
    }
    else
    {
        printf("Ocurrio un error");
    }
}

Escopeta *Crear_Escopeta(int municion, float tiempo_recarga, int dano)
{
    Escopeta *nueva_escopeta = (Escopeta *)malloc(sizeof(Escopeta));

    nueva_escopeta->arma = *Crear_Arma(municion, tiempo_recarga, dano);
    nueva_escopeta->arma.disparar_func = __Disparar_Escopeta;
    nueva_escopeta->arma.nombre_func = __Nombre_Arma_Pistola;
    nueva_escopeta->canon_doble = 2;

    nueva_escopeta->arma.dano += nueva_escopeta->canon_doble;

    return nueva_escopeta;
}

void Destruir_Escopeta(Escopeta *esta_escopeta)
{
    Destruir_Arma((Gun*)esta_escopeta);
}