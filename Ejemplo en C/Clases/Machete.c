#include "string.h"
#include "stdlib.h"

#include "Machete.h"

Machete *Crear_Machete(int daño)
{
    Machete *machete = (Machete*) malloc(sizeof(Machete));
    machete->daño = 10;
}

void Destruir_Machete(Machete *este_machete)
{
    free(este_machete);
}