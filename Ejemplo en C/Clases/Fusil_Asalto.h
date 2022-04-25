#ifndef _FUSIL_ASALTO_H_
#define _FUSIL_ASALTO_H_

#include "Arma.h"

typedef struct _fusil_asalto{
    Arma arma;
    unsigned int cargador_ampliado;
} Fusil_Asalto;

Fusil_Asalto *Crear_Fusil_Asalto(int municion, float tiempo_recarga, int daño);
void Destruir_Fusil_Asalto(Fusil_Asalto *este_fusil_asalto);
char *ToString();

#endif