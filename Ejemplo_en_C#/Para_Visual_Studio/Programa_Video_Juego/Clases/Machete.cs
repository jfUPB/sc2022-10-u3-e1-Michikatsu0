using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programa_Video_Juego.Clases
{
    class Machete
    {
        private int daño;
        
        public Machete()
        {
            daño = 10;
        }

        public int Daño { get => daño; set => daño = value; }
    }
}
