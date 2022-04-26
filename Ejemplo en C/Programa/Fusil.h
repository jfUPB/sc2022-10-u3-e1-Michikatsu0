#ifndef _FUSIL_H_
#define _FUSIL_H_

#include "Gun.h"

typedef struct {
    Gun arma;
    unsigned int cargador_ampliado;
} Fusil;

Fusil *Crear_Fusil_Asalto(int municion, float tiempo_recarga, int dano);
void Destruir_Fusil_Asalto(Fusil *este_fusil_asalto);

#endif

