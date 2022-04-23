using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Escopeta : Arma
    {
        private byte cañon_doble;

        public Escopeta(int municion, float tiempo_recarga, int daño) : base(municion, tiempo_recarga, daño)
        {
            cañon_doble = 2;
            Municion = municion;
            Tiempo_recarga = tiempo_recarga;
            Daño = daño * cañon_doble;
        }
        public override string Disparar(Enemigo objetivo)
        {
            if (municion > 0)
            {

                if (objetivo.Vida <= 0)
                {
                    objetivo.Vida = 0;
                    return "\nNo se pudo disparar la ESCOPETA, el ENEMIGO esta muerto." + "\nVida del objetivo: " + objetivo.Vida + "\nMunicion: " + municion;
                }
                else
                {
                    objetivo.Vida -= daño;
                    municion -= 2;
                }
                return "\nSe disparo la ESCOPETA" + "\nVida del objetivo: " + objetivo.Vida + "\nMunicion: " + municion;
            }
            else if (municion <= 0)
            {
                return "\nNo se pudo disparar la ESCOPETA, no tiene municion." + municion;
            }
            else
            {
                return "Ocurrio un error";
            }
        }
    }
}
