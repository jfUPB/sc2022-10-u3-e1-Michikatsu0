#include "string.h"
#include "stdlib.h"

#include "Fusil_Asalto.h"
#include "Arma.h"


Fusil_Asalto *Crear_Fusil_Asalto(int municion, float tiempo_recarga, int daño)
{
    Fusil_Asalto *nuevo_fusil_asalto = (Fusil_Asalto *)malloc(sizeof(Fusil_Asalto));
    Arma *fusil_asalto_datos = Crear_Arma(municion, tiempo_recarga, daño);

    nuevo_fusil_asalto->cargador_ampliado = 3;
    nuevo_fusil_asalto->arma.municion = fusil_asalto_datos->municion * nuevo_fusil_asalto->cargador_ampliado;
    nuevo_fusil_asalto->arma.tiempo_recarga = fusil_asalto_datos->tiempo_recarga;
    nuevo_fusil_asalto->arma.daño = fusil_asalto_datos->daño;

    return nuevo_fusil_asalto;
}
void Destruir_Fusil_Asalto(Fusil_Asalto *este_fusil_asalto)
{
    Destruir_Arma((Arma*)este_fusil_asalto);
    free(este_fusil_asalto);
}

void Disparar(Enemigo *objetivo, Arma *este_fusil_asalto)
{
    if ( objetivo->vida > 0)
    {

        if (objetivo->vida <= 0)
        {
            objetivo->vida = 0;
            printf("No se pudo disparar la Pistola, el Enemigo ya esta muerto.\nVida del objetivo: %d", objetivo->vida, "\nMunicion: %d", este_fusil_asalto->municion);
        }
        else
        {
            objetivo->vida -= este_fusil_asalto->daño;
            este_fusil_asalto->daño -= 1;
        }

        printf("Se disparo la Pistola.\nVida del objetivo: %d", objetivo->vida, "\nMunicion: &d", este_fusil_asalto->municion);
    }
    else if (este_fusil_asalto->municion <= 0)
    {
        printf("No se pudo disparar la Pistola. Sin municion: %d", este_fusil_asalto->municion);
    }
    else
    {
        printf("Ocurrio un error");
    }
}

char *ToString()
{
    return "Fusil de Asalto";
}