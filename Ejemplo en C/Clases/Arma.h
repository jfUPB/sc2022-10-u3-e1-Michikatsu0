#ifndef _ARMA_H
#define _ARMA_H

#include "Enemigo.h"

typedef void (*disparar_func_t)(void *);

typedef struct _arma
{
    int municion;
    float tiempo_recarga;
    int daño;
    disparar_func_t disparar_func;
} Arma;

//tamaña en memoria
Arma *Crear_Arma(int municion, float tiempo_recarga, int daño); //Constructor
void Destruir_Arma(Arma *esta_arma);
void Disparar(Enemigo *objetivo, Arma *esta_arma); //implementar polimorfismo
char *ToString();  
#endif
