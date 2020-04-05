using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2CSharp
{
    public class LinearEquation
    {
        double[] coefficients;

        public static implicit operator double[] (LinearEquation le)
        {
            return le.coefficients;
        }
    }
}
