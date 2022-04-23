using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Enemigo
    {
        private int vida;
        private Machete arma;

        public Enemigo(int vida)
        {
            this.vida = vida;
            arma = new Machete();
        }

        public int Vida { get => vida; set => vida = value; }

        public string Lanzar_Machete(Jugador objetivo)
        {
            objetivo.Vida -= arma.Daño;
            return "Vida del Soldado: " + objetivo.Vida;
        }
    }
}
