using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2CSharp
{
    public class SystemOfLinearEquation
    {
        LinearEquation[] equations;

        public SystemOfLinearEquation(int m)
        {
            if (m <= 0)
            {
                throw new ArgumentException();
            }
            this.equations = new LinearEquation[m];
            for(int i = 0; i < m; i++)
            {
                this.equations[i] = new LinearEquation(2);
            }
        }

        public LinearEquation this[int i]
        {
            get
            {
                if (i < 0 || i >= this.equations.Length)
                {
                    throw new ArgumentException();
                }
                return this.equations[i];
            }
            set 
            {
                if (i < 0 || i >= this.equations.Length)
                {
                    throw new ArgumentException();
                }
                this.equations[i] = new LinearEquation(value);
            }
        }

        public void ToTriangular()
        {
            Array.Sort(this.equations, (x, y) => (-1 * x.Degree.CompareTo(y.Degree)));
            int maxDegree = this.equations[0].Degree,
                degreeLimit = Math.Max(maxDegree - this.equations.Length, 1),
                numberOfEquation = 0;
            for (int d = maxDegree; d >= degreeLimit; d--)
            {
                if (this.equations[numberOfEquation].Degree < d)
                    continue;
                for (int i = numberOfEquation + 1; i < this.equations.Length; i++)
                {
                    this.equations[i] = this.equations[i] - this.equations[numberOfEquation] * (this.equations[i][d] / this.equations[numberOfEquation][d]);
                }
                numberOfEquation += 1;
            }
        }

        

        public override string ToString()
        {
            string result = "";
            for(int i = 0; i < this.equations.Length; i++)
            {
                result += this.equations[i] + "\n";
            }
            return result;
        }
    }
}
