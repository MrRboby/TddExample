using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1
{
    public class Indexer
    {
        double[] array;
        int firstIndex, lastIndex;
        public Indexer(double[] array, int firstIndex, int length)
        {
            this.array = array;
            this.firstIndex = firstIndex;
            this.lastIndex = firstIndex + length;
        }
        public int Length
        {
            get => this.lastIndex - this.firstIndex;
        }
        public double this[int index]
        {
            get
            {
                return this.array[index + firstIndex];
            }
            set
            {
                this.array[index] = value;
            }
        }

    }
}
