#include <stdlib.h>
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

struct threadParam_t
{
    VideoJuego *nuevo_video_juego;
    Enemigo (*l_enemigos)[10];
    bool tecla_presionada;
    char * buffer_tecla;
    int mira;
    int tno_l_enemigos;
};

void *Juego(void *data)
{
    struct threadParam_t *dataTmp = (struct threadParam_t*)data;
    while (true)
    {
        printf("...");
        if (Ganador(dataTmp->nuevo_video_juego) == true)
        {

            printf("Ganaste el juego... Puntos: %i", dataTmp->nuevo_video_juego->puntos);
            sleep(5);
            return EXIT_SUCCESS;
        }
        else if (Perdedor(dataTmp->nuevo_video_juego) == true)
        {

            printf("Perdiste el juego... Puntos: %i", dataTmp->nuevo_video_juego->puntos);
            sleep(5);
            return EXIT_SUCCESS;
        }

        sleep(1);
    }
}

void *Teclado_P(void *data)
{
    struct threadParam_t *dataTmp = (struct threadParam_t*)data;
    
    while (true)
    {
        scanf("%c", dataTmp->buffer_tecla);
        dataTmp->tecla_presionada = true;

        if (dataTmp->tecla_presionada)
        {
            dataTmp->tecla_presionada = false;
            switch ( *(dataTmp->buffer_tecla))
            {
            case 'a':
                Recargar_Arma(dataTmp->nuevo_video_juego->soldado); //
                break;
            case 's':
                Disparar_Arma(dataTmp->nuevo_video_juego->soldado, dataTmp->l_enemigos[dataTmp->mira], dataTmp->nuevo_video_juego);
                printf("Mira apuntando a Zombie Nro: %i", dataTmp->mira);
                break;
            case 'd':
                Cambiar_Arma(dataTmp->nuevo_video_juego->soldado);
                break;
            case 'w':
                dataTmp->mira++;
                if (dataTmp->mira == dataTmp->tno_l_enemigos)
                {
                    dataTmp->mira = -1;
                }
                printf("Mira cambiada a Zombie Nro: %i", dataTmp->mira);
                break;
            case 'x':
                Lanzar_Machete(dataTmp->l_enemigos[dataTmp->mira], dataTmp->nuevo_video_juego->soldado);
                break;
            case 'c':
                dataTmp->tno_l_enemigos++;
                //+ dataTmp->tno_l_enemigos))    
                dataTmp->l_enemigos[0]  = Crear_Enemigo(50);
                printf("Hay %i zombies con vida.", dataTmp->tno_l_enemigos);
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
    VideoJuego *nuevo_video_juego = Crear_Video_Juego();
    Enemigo l_enemigos[10];
    char buffer;
    for (int8_t i = 0; i < 10; i++)
    {
        l_enemigos[i] = *(Enemigo *)malloc(sizeof(Enemigo));
    }

    // Treads teclado y game
    pthread_t thread1;
    pthread_t thread2;
    

    struct threadParam_t threadParam = {nuevo_video_juego, (Enemigo (*)[])l_enemigos, false, &buffer ,0, 0};

    pthread_create(&thread1, NULL, &Teclado_P, &threadParam);
    pthread_create(&thread2, NULL, &Juego, &threadParam);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    exit(EXIT_SUCCESS);
}