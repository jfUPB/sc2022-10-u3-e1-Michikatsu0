#include <stdlib.h>
#include <stdio.h>
#include "Arma.h"

Arma *Crear_Arma(int municion, float tiempo_recarga, int daño)
{
    Arma *nueva_arma = (Arma *) malloc(sizeof(Arma));

    nueva_arma->municion = municion;
    nueva_arma->tiempo_recarga = tiempo_recarga;
    nueva_arma->daño = daño;

    return nueva_arma;
}

void Destruir_Arma(Arma *esta_arma){
    free(esta_arma);
}

void Disparar(Enemigo *objetivo, Arma *esta_arma) 
{
    return "OWO"; //polimorfismo?
}

char *ToString()
{
    return "Arma"; //polimorfismo?
}