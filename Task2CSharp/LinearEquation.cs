using System;
using System.Collections.Generic;
using System.Linq;

namespace Task2CSharp
{
    public class LinearEquation
    {
        double[] coefficients;

        public LinearEquation(string str)
        {
            string[] sArr = str.Split(new char[] { ' ', '\t', '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries);
            if (sArr.Length == 0)
                this.coefficients = new double[] { 0, 0 };
            else if (sArr.Length == 1)
            {
                try
                {
                    this.coefficients = new double[] { double.Parse(sArr[0]), 0 };
                }
                catch
                {
                    throw new ArgumentException();
                }
            }
            else
            {
                this.coefficients = new double[sArr.Length];
                try
                {
                    for (int i = 0; i < sArr.Length; i++)
                        this.coefficients[i] = double.Parse(sArr[i]);
                }
                catch
                {
                    throw new ArgumentException();
                }
            }
        }

        public LinearEquation(IList<double> list)
        {
            if (list.Count == 0)
                this.coefficients = new double[] { 0, 0 };
            else if (list.Count == 1)
            {
                this.coefficients = new double[] { list[0], 0 };
            }
            else
            {
                this.coefficients = (double[])list.ToArray().Clone();
            }
        }

        public LinearEquation(LinearEquation le)
        {
            this.coefficients = (double[])le.coefficients.Clone();
        }

        public LinearEquation(int n)
        {
            if (n >= 2)
            {
                this.coefficients = new double[n];
            }
            else if (n >= 0)
            {
                this.coefficients = new double[2];
            }
            else
            {
                throw new ArgumentException();
            }
        }

        public void FillByDuplicates(double number)
        {
            this.coefficients = Enumerable.Repeat(number, this.coefficients.Length).ToArray();
        }
        public void FillByRandom(int minValue, int maxValue, int seed)
        {
            if (maxValue < minValue)
            {
                throw new ArgumentException();
            }
            Random Rand = new Random(seed);
            for(int i = 0; i < this.coefficients.Length; i++)
            {
                this.coefficients[i] = Rand.NextDouble() * (maxValue - minValue) + minValue;
            }
        }

        public void FillByRandom(int minValue, int maxValue)
        {
            if (maxValue < minValue)
            {
                throw new ArgumentException();
            }
            Random Rand = new Random();
            for (int i = 0; i < this.coefficients.Length; i++)
            {
                this.coefficients[i] = Rand.NextDouble() * (maxValue - minValue) + minValue;
            }
        }

        public static implicit operator double[](LinearEquation le)
        {
            return le.coefficients;
        }
    }
}
