#ifndef _PISTOLA_H_
#define _PISTOLA_H_

#include "Arma.h"

typedef struct _pistola{
    Arma arma;
    float cargador_rapido;
} Pistola;

Pistola *Crear_Pistola(int municion, float tiempo_recarga, int daño);
void Destruir_Pistola(Pistola *este_fusil_asalto);
char *ToString();

#endif