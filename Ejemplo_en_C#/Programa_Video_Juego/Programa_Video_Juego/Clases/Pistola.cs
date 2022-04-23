using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Pistola : Arma
    {
        private float cargador_rapido;

        public Pistola(int municion, float tiempo_recarga, int daño) : base(municion, tiempo_recarga, daño)
        {
            cargador_rapido = 1.5f;
            Municion = municion;
            Tiempo_recarga = tiempo_recarga - cargador_rapido;
            Daño = daño;
        }

        public override string Disparar(Enemigo objetivo)
        {
            if (municion > 0)
            {
                
                if (objetivo.Vida <= 0)
                {
                    objetivo.Vida = 0;
                    return "\nNo se pudo disparar la PISTOLA, el ENEMIGO esta muerto." + "\nVida del objetivo: " + objetivo.Vida + "\nMunicion: " + municion;
                }
                else
                {
                    objetivo.Vida -= daño;
                    municion -= 1;
                }
                
                return "\nSe disparo la PISTOLA" + "\nVida del objetivo: " + objetivo.Vida + "\nMunicion: " + municion;
            }
            else if (municion <= 0)
            {
                return "\nNo se pudo disparar la PISTOLA, no tiene municion." + municion;
            }
            else
            {
                return "Ocurrio un error";
            }
        }
    }
}
