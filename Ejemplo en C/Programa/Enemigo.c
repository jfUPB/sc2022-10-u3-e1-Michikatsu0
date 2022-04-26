#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "Enemigo.h"
#include "Player.h"

Enemigo *Crear_Enemigo(int vida)
{
    Enemigo *nuevo_enemigo = (Enemigo*)malloc(sizeof(Enemigo));
    nuevo_enemigo->vida = vida;
    nuevo_enemigo->arma = Crear_Machete(10);

    return nuevo_enemigo;
}
void Destruir_Enemigo(Enemigo *este_enemigo)
{
    free(este_enemigo);
}

void Lanzar_Machete(Enemigo *este_enemigo, void *objetivo)
{
    Player *nuevo_objetivo = (Player*)objetivo;
    nuevo_objetivo->vida -= este_enemigo->arma->dano;   
    printf("Vida del Soldado: %d", nuevo_objetivo->vida);
}

