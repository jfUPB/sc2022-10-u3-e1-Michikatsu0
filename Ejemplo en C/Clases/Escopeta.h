#ifndef _ESCOPETA_H_
#define _ESCOPETA_H_

#include "Arma.h"

typedef struct _escopeta{
    Arma arma;
    unsigned int cañon_doble;
} Escopeta;

Escopeta *Crear_Escopeta(int municion, float tiempo_recarga, int daño);
void Destruir_Escopeta(Escopeta *esta_escopeta);
char *ToString();

#endif
