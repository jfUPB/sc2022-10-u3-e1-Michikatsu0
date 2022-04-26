#ifndef _ESCOPETA_H_
#define _ESCOPETA_H_

#include "Gun.h"
#include "Enemigo.h"

typedef struct {
    Gun arma;
    int canon_doble;
} Escopeta;

Escopeta *Crear_Escopeta(int municion, float tiempo_recarga, int dano);
void Destruir_Escopeta(Escopeta *esta_escopeta);



#endif