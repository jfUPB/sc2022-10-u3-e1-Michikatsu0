#include "string.h"
#include "stdlib.h"

#include "Pistola.h"
#include "Arma.h"


Pistola *Crear_Pistola(int municion, float tiempo_recarga, int daño)
{
    Pistola *nueva_pistola = (Pistola*) malloc(sizeof(Pistola));
    Arma *pistola_datos = Crear_Arma(municion,tiempo_recarga,daño);

    nueva_pistola->cargador_rapido = 1.5f;
    nueva_pistola->arma.daño = pistola_datos->daño;
    nueva_pistola->arma.municion = pistola_datos->municion;
    nueva_pistola->arma.tiempo_recarga = pistola_datos->tiempo_recarga + nueva_pistola->cargador_rapido;

    return nueva_pistola;
}
void Destruir_Pistola(Pistola *esta_pistola){
    Destruir_Arma((Arma*)esta_pistola);
    free(esta_pistola);
}


void Disparar(Enemigo *objetivo, Arma *esta_pistola)
{
    if ( objetivo->vida > 0)
    {

        if (objetivo->vida <= 0)
        {
            objetivo->vida = 0;
            printf("No se pudo disparar la Pistola, el Enemigo ya esta muerto.\nVida del objetivo: %d", objetivo->vida, "\nMunicion: %d", esta_pistola->municion);
        }
        else
        {
            objetivo->vida -= esta_pistola->daño;
            esta_pistola->municion -= 1;
        }

        printf("Se disparo la Pistola.\nVida del objetivo: %d", objetivo->vida, "\nMunicion: &d", esta_pistola->municion);
    }
    else if (esta_pistola->municion <= 0)
    {
        printf("No se pudo disparar la Pistola. Sin municion: %d", esta_pistola->municion);
    }
    else
    {
        printf("Ocurrio un error");
    }
}

char *ToString()
{
    return "Pistola";   
}