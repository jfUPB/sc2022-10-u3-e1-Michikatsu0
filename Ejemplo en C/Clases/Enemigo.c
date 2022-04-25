#include <stdlib.h>
#include <stdio.h>

#include "Enemigo.h"

Enemigo *Crear_Enemigo(int vida)
{
    Enemigo *nuevo_enemigo = (Enemigo*) malloc(sizeof(Enemigo));
    
    nuevo_enemigo->vida = vida;   
    Machete *nuevo_machete = Crear_Machete(10);
    nuevo_enemigo->arma = *nuevo_machete;  
}

void Destruir_Enemigo(Enemigo *este_enemigo, Machete *este_machete)
{
    free(este_enemigo);
    Destruir_Machete(este_machete);
}

void Lanzar_Machete(Jugador *objetivo){
    objetivo->vida = -10;
}