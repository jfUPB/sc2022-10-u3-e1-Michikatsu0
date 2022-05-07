#ifndef _PISTOLA_H_
#define _PISTOLA_H_

#include "Gun.h"

typedef struct {
    Gun arma;
    float cargador_rapido;
} Pistola;

Pistola *Crear_Pistola(int municion, float tiempo_recarga, int dano);
void Destruir_Pistola(Pistola *esta_pistola);

#endif