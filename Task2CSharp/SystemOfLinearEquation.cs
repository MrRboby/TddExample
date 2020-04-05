﻿using System;
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