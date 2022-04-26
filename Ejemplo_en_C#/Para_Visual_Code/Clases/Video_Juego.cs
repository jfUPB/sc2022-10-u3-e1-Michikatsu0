using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Video_Juego
    {
        List<Enemigo> l_zombies;
        Jugador soldado;
        uint puntos;

        public Video_Juego()
        {
            l_zombies = new List<Enemigo>();
            soldado = new Jugador();
            puntos = 0;
        }

        public uint Puntos { get => puntos; set => puntos = value; }
        public List<Enemigo> L_zombies { get => l_zombies; set => l_zombies = value; }
        public Jugador Soldado { get => soldado; set => soldado = value; }

        public bool Ganador()
        {
            if (puntos >= 100)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool Perdedor()
        {
            if (soldado.Vida <= 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
