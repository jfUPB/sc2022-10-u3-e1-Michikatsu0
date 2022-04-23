using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Jugador
    {
        private int vida;
        private List<Arma> l_armas;
        private Arma arma_actual;
        private static int estado_arma = 0;
        private static int tipo_municion = 0;

        public Jugador()
        {
            vida = 30;

            l_armas = new List<Arma>();
            Pistola pistola = new Pistola(6, 2f, 10);
            Escopeta escopeta = new Escopeta(4, 4f, 10);
            Fusil_Asalto fusil = new Fusil_Asalto(15, 3.5f, 10);
            l_armas.Add(pistola);
            l_armas.Add(escopeta);
            l_armas.Add(fusil);

            arma_actual = l_armas[0];

        }

        public int Vida { get => vida; set => vida = value; }
        public List<Arma> L_armas { get => l_armas; set => l_armas = value; }
        public Arma Arma_actual { get => arma_actual; set => arma_actual = value; }

        public string Disparar_Arma(Enemigo objetivo, Video_Juego video_juego)
        {
            
            if (objetivo.Vida > 0)
            {
                video_juego.Puntos += 5;
                return arma_actual.Disparar(objetivo) + "\nSe diparó el arma: " + arma_actual.ToString() + "\nPuntos: " + video_juego.Puntos;
            }
            else if (objetivo.Vida <= 0)
            {
                video_juego.Puntos += 0;
                return arma_actual.Disparar(objetivo) + "\nNo se diparó el arma: " + arma_actual.ToString() + "\nPuntos: " + video_juego.Puntos;
            }
            else
                return "Ocurrio un error";
            
        }

        public string Cambiar_Arma()
        {
            estado_arma++;
            arma_actual = l_armas[estado_arma];
            if (estado_arma == 2)
                estado_arma = -1;
            return "Arma actual: " + arma_actual.ToString();
        }

        public string Recargar_Arma()
        {
            int[] l_municiones = { 6, 4, 15 };
            string[] l_nombres_armas = { "Pistola", "Escopeta", "Fusil de Asalto" };
            if (arma_actual.Municion == 0)
            {
                if (estado_arma == 0) //pistola
                {
                    tipo_municion = 0;
                    arma_actual.Municion += l_municiones[tipo_municion];
                    return "\nSe recargo: " + l_nombres_armas[0] + "\nMunicion: " + arma_actual.Municion;
                }
                else if (estado_arma == 1) //escopeta
                {
                    tipo_municion = 1;
                    arma_actual.Municion += l_municiones[tipo_municion];
                    return "\nSe recargo: " + l_nombres_armas[1] + "\nMunicion: " + arma_actual.Municion;
                }
                else if (estado_arma == 2) //fusil de asalto
                {
                    tipo_municion = 2;
                    arma_actual.Municion += l_municiones[tipo_municion];
                    return "\nSe recargo: " + l_nombres_armas[2] + "\nMunicion: " + arma_actual.Municion;
                }
                else
                    return "\nOcurrio un error";

            }
            else
                return "\nNo se pudo recargar: " + arma_actual.ToString() + "\nMunicion: " + arma_actual.Municion;
        }

    }
}
