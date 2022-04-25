#include <stdlib.h>
#include <stdio.h>

#include "Escopeta.h"
#include "Arma.h"

Escopeta *Crear_Escopeta(int municion, float tiempo_recarga, int daño)
{
    Escopeta *nueva_escopeta = (Escopeta *)malloc(sizeof(Escopeta));
    Arma *escopeta_datos = Crear_Arma(municion, tiempo_recarga, daño);

    nueva_escopeta->cañon_doble = 2;
    nueva_escopeta->arma.municion = escopeta_datos->municion;
    nueva_escopeta->arma.tiempo_recarga = escopeta_datos->tiempo_recarga;
    nueva_escopeta->arma.daño = escopeta_datos->daño + nueva_escopeta->cañon_doble;

    return nueva_escopeta;
}

void Destruir_Escopeta(Escopeta *esta_escopeta)
{
    Destruir_Arma((Arma*)esta_escopeta);
    free(esta_escopeta);
}

void Disparar(Enemigo *objetivo, Arma *esta_escopeta)
{
    if ( objetivo->vida > 0)
    {

        if (objetivo->vida <= 0)
        {
            objetivo->vida = 0;
            printf("No se pudo disparar la Escopeta, el Enemigo ya esta muerto.\nVida del objetivo: %d", objetivo->vida, "\nMunicion: %d", esta_escopeta->municion);
        }
        else
        {
            objetivo->vida -= esta_escopeta->daño;
            esta_escopeta->municion -= 2;
        }
        printf("Se disparo la Escopeta.\nVida del objetivo: %d", objetivo->vida, "\nMunicion: &d", esta_escopeta->municion);
    }
    else if (esta_escopeta->municion <= 0)
    {
        printf("No se pudo disparar la Escopeta. Sin municion: %d", esta_escopeta->municion);
    }
    else
    {
        printf("Ocurrio un error");
    }
}

char *ToString()
{
    return "Escopeta";   
}