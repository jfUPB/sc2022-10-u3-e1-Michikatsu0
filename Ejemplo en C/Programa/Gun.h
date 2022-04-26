#ifndef _GUN_H
#define _GUN_H

typedef void (*disparar_func_t)(void *, void* );

typedef void (*nombre_func_t)(void *);

typedef struct _gun
{
    int municion;
    float tiempo_recarga;
    int dano;
    disparar_func_t disparar_func;
    nombre_func_t nombre_func;

} Gun;

Gun *Crear_Arma(int municion, float tiempo_recarga, int dano); //Constructor
void Destruir_Arma(Gun *esta_arma);

void Disparar(Gun *esta_arma, void *objetivo);
void Nombre_Arma(Gun *esta_arma);

#endif