using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            SystemOfLinearEquation sle = new SystemOfLinearEquation(3);
            //sle[0] = new LinearEquation(new double[] { 1, 2 });
            //sle[1] = new LinearEquation(new double[] { 1, 2, 6 });
            sle[0] = new LinearEquation(new double[] { -8, -1, 1, 2 });
            sle[1] = new LinearEquation(new double[] { 11, 2, -1, -3 });
            sle[2] = new LinearEquation(new double[] { 3, 2, 1, -2 });
            sle.ToTriangular();
        }
    }
}
