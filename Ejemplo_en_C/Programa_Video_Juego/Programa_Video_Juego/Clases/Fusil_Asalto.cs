using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Fusil_Asalto : Arma
    {
        private byte cargador_ampliado;

        public Fusil_Asalto(int municion, float tiempo_recarga, int daño) : base(municion, tiempo_recarga, daño)
        {
            cargador_ampliado = 3;
            Municion = municion * cargador_ampliado;
            Tiempo_recarga = tiempo_recarga;
            Daño = daño;
        }

        public override string Disparar(Enemigo objetivo)
        {
            if (municion > 0)
            {
                if (objetivo.Vida <= 0)
                {
                    objetivo.Vida = 0;
                    return "\nNo se pudo disparar el FUSIL de ASALTO, el ENEMIGO esta muerto." + "\nVida del objetivo: " + objetivo.Vida + "\nMunicion: " + municion;
                }
                else
                {
                    objetivo.Vida -= daño;
                    municion -= 1;
                }
                return "\nSe disparo el FUSIL de ASALTO" + "\nVida del objetivo: " + objetivo.Vida + "\nMunicion: " + municion;
            }
            else if (municion <= 0)
            {
                return "\nNo se pudo disparar el FUSIL de ASALTO, no tiene municion." + municion;
            }
            else
            {
                return "Ocurrio un error";
            }
        }
    }
}
