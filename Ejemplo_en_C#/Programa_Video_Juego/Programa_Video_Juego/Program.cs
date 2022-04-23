using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Programa_Video_Juego.Clases;
using System.Threading;

public enum EstadosVideoJuego { INIT, GAME };

namespace Programa_Video_Juego
{
    class Program
    {
        public static Video_Juego video_juego = new Video_Juego();

        public static List<Enemigo> l_zombies = new List<Enemigo>();

        public static int mira = 0;

        static void Main(string[] args)
        {
            for (uint i = 0; i < 3; i++)
            {
                Enemigo zombie1 = new Enemigo(50);
                l_zombies.Add(zombie1);
            }

            Thread teclado = new Thread(Teclado);
            teclado.Start();

            while (true)
            {
                Console.WriteLine("...");

                if (video_juego.Ganador() == true)
                {
                    Console.WriteLine("Ganaste el juego...Puntos: " + video_juego.Puntos);
                    Console.ReadKey();
                    Environment.Exit(0);
                }
                else if (video_juego.Perdedor() == true)
                {
                    Console.WriteLine("Perdiste el Juego... Puntos: " + video_juego.Puntos);
                    Console.ReadKey();
                    Environment.Exit(0);
                }

                Thread.Sleep(300);
            }


        }

        static void Teclado()
        {
            while (true)
            {
                if (Console.KeyAvailable == true)
                {
                    Acciones();
                }

            }
        }

        static void Acciones()
        {

            switch (Console.ReadKey(true).Key)
            {
                case ConsoleKey.A:
                    Console.WriteLine(video_juego.Soldado.Recargar_Arma());
                    break;

                case ConsoleKey.S:
                    Console.WriteLine(video_juego.Soldado.Disparar_Arma(l_zombies[mira], video_juego));
                    break;

                case ConsoleKey.D:
                    Console.WriteLine(video_juego.Soldado.Cambiar_Arma());
                    break;

                case ConsoleKey.W:
                        mira++;
                    if (mira == l_zombies.Count)
                        mira = 0;
                    Console.WriteLine("Cambiado a Zombie Nro: " + mira);
                    break;

                case ConsoleKey.X:
                    Console.WriteLine(l_zombies[mira].Lanzar_Machete(video_juego.Soldado));
                    break;
                case ConsoleKey.C:
                    Enemigo zombie_extra = new Enemigo(50);
                    l_zombies.Add(zombie_extra);
                    Console.WriteLine("Hay " + l_zombies.Count + " zombies con vida.");
                    break;
            }
        }




    }
}
