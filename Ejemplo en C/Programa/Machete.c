#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Machete.h"

Machete *Crear_Machete(int dano)
{
    Machete *nuevo_machete = (Machete*) malloc(sizeof(Machete));
    nuevo_machete->dano = dano;

    return nuevo_machete;
}
void Destruir_Machete(Machete *este_machete){
    free(este_machete);
}