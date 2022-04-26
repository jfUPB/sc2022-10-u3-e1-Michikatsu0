using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    abstract class Arma
    {
        protected int municion;
        protected float tiempo_recarga;
        protected int daño;

        public Arma(int municion, float tiempo_recarga, int daño)
        {
            Municion = municion;
            Tiempo_recarga = tiempo_recarga;
            Daño = daño;
        }

        public int Municion { get => municion; set => municion = value; }
        public float Tiempo_recarga { get => tiempo_recarga; set => tiempo_recarga = value; }
        public int Daño { get => daño; set => daño = value; }

        public abstract string Disparar(Enemigo objetivo);
    }
}
