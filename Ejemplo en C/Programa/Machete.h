#ifndef _MACHETE_H
#define _MACHETE_H

typedef struct _machete
{
   int dano;
} Machete;

Machete *Crear_Machete(int dano);
void Destruir_Machete(Machete *este_machete);

#endif