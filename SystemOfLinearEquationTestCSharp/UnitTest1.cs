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
        [TestMethod]
        public void Get()
        {
            SystemOfLinearEquation sle = new SystemOfLinearEquation(1);
            Assert.AreEqual("0=0", sle[0].ToString());
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void GetWithIncorrectArgument()
        {
            SystemOfLinearEquation sle = new SystemOfLinearEquation(1);
            Assert.Equals(typeof(ArgumentException), sle[-4].ToString());
        }
        [TestMethod]
        public void SetAndGet()
        {
            SystemOfLinearEquation sle = new SystemOfLinearEquation(2);
            sle[0] = new LinearEquation(new double[] { 1, 2, 3 });
            Assert.AreEqual("3x1+2x2+1=0", sle[0].ToString());
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void SetWithIncorrectArgument()
        {
            SystemOfLinearEquation sle = new SystemOfLinearEquation(2);
            Assert.Equals(typeof(ArgumentException), sle[3] = new LinearEquation(new double[4] { 1, 2, 3, 6 }));
        }
    }
}