#ifndef _MACHETE_H
#define _MACHETE_H

typedef struct _machete
{
   int daño;
} Machete;

Machete *Crear_Machete(int daño);
void Destruir_Machete(Machete *este_machete);

#endif