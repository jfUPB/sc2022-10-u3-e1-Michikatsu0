#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "VideoJuego.h"
#include "Enemigo.h"
#include "Gun.h"
#include "Escopeta.h"
#include "Fusil.h"
#include "Pistola.h"
#include "Player.h"
#include "Machete.h"

static VideoJuego *nuevo_video_juego;
static Enemigo *l_enemigos[10];
static bool tecla_presionada = false;
static char buffer_tecla;
static int mira = 0;
static int tno_l_enemigos = -1;

void *Juego(void *data)
{

    while (true)
    {
        printf("...");
        if (Ganador(nuevo_video_juego) == true)
        {

            printf("Ganaste el juego... Puntos: %i", nuevo_video_juego->puntos);
            sleep(5);
            return EXIT_SUCCESS;
        }
        else if (Perdedor(nuevo_video_juego) == true)
        {

            printf("Perdiste el juego... Puntos: %i", nuevo_video_juego->puntos);
            sleep(5);
            return EXIT_SUCCESS;
        }

        sleep(1);
    }
}

void *Teclado_P(void *data)
{
    while (true)
    {
        scanf("%c", &buffer_tecla);
        tecla_presionada = true;

        if (tecla_presionada)
        {
            tecla_presionada = false;
            switch (buffer_tecla)
            {
            case 'a':
                Recargar_Arma(nuevo_video_juego->soldado);//
                break;
            case 's':
                Disparar_Arma(nuevo_video_juego->soldado, l_enemigos[mira], nuevo_video_juego);
                printf("Mira apuntando a Zombie Nro: %i", mira);
                break;
            case 'd':
                Cambiar_Arma(nuevo_video_juego->soldado);
                break;
            case 'w':
                mira++;
                if (mira == tno_l_enemigos)
                {
                    mira = -1;
                }
                printf("Mira cambiada a Zombie Nro: %i", mira);
                break;
            case 'x':
                Lanzar_Machete(l_enemigos[mira], nuevo_video_juego->soldado);
                break;
            case 'c':
                tno_l_enemigos++;
                l_enemigos[tno_l_enemigos] = Crear_Enemigo(50);
                printf("Hay %i zombies con vida.", tno_l_enemigos);
                break;
            default:
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Crear el video juego en cosola
    nuevo_video_juego = Crear_Video_Juego();
    for (int8_t i = 0; i < 10; i++)
    {
        l_enemigos[i] = (Enemigo *)malloc(sizeof(Enemigo));
    }
    for (int8_t i = 0; i < 3; i++)
    {
        Enemigo *nuevo_enemigo = Crear_Enemigo(50);
        l_enemigos[i] = nuevo_enemigo;
        tno_l_enemigos++;
    }

    // Treads teclado y game
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, &Teclado_P, 0);
    pthread_create(&thread2, NULL, &Juego, 0);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    exit(EXIT_SUCCESS);
}