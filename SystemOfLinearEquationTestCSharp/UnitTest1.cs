using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Task2CSharp;

namespace SystemOfLinearEquationTestCSharp
{
    [TestClass]
    public class UnitTestSystemOfLinearEquation
    {
        [TestMethod]
        public void Constructor()
        {
            int m = 2;
            SystemOfLinearEquation sle = new SystemOfLinearEquation(m);
            Assert.AreEqual("0=0\n0=0\n", sle.ToString());
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void ConstructorWithNegativeArgument()
        {
            int m = -2;
            Assert.Equals(typeof(ArgumentException), new SystemOfLinearEquation(m));
        }

    }
}
