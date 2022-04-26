#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Gun.h"
#include "Enemigo.h"

void __Nombre_Arma()
{
    printf("Arma");
}

void __Disparar(void *esta_arma, void *este_enemigo)
{
    Gun *ref_arma = (Gun *)esta_arma;
    Enemigo *ref_enemigo = (Enemigo*)este_enemigo;
    printf("OWO: las armas no se disparan solas...\nMunicion: %d\nVida del Enemigo: %d", ref_arma->municion, ref_enemigo->vida);
}

// Constructor y Memoria
Gun *Crear_Arma(int municion, float tiempo_recarga, int dano)
{
    Gun *nueva_arma = (Gun *)malloc(sizeof(Gun));

    nueva_arma->municion = municion;
    nueva_arma->tiempo_recarga = tiempo_recarga;
    nueva_arma->dano = dano;
    nueva_arma->disparar_func = &__Disparar;
    nueva_arma->nombre_func = &__Nombre_Arma;

    return nueva_arma;
}
void Destruir_Arma(Gun *esta_arma)
{
    free(esta_arma);
}

// Metodos
void Disparar(Gun *esta_arma, void *objetivo)
{
    esta_arma->disparar_func(esta_arma, objetivo);
}

void Nombre_Arma(Gun *esta_arma)
{
    esta_arma->nombre_func(esta_arma);
}
