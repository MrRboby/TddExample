using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Linq;
using System.Collections.Generic;
using Task2CSharp;

namespace LinearEquationTestCSharp
{
    [TestClass]
    public class UnitTestLinearEquation
    {
        [TestMethod]
        public void StringConstructor()
        {
            string s = "1 1.5 2.6 -4 89 13.4";
            LinearEquation le = new LinearEquation(s);
            Assert.IsTrue(new double[] { 1, 1.5, 2.6, -4, 89, 13.4 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void StringConstructorWithEmptyString()
        {
            string s = "";
            LinearEquation le = new LinearEquation(s);
            Assert.IsTrue(new double[] { 0, 0 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void StringConstructorWithIncorrectString()
        {
            string s = "1 g 2.25 -5.7 helloworld 3 k";
            Assert.Equals(typeof(ArgumentException), new LinearEquation(s));
        }
        [TestMethod]
        public void ListConstructorWithArray()
        {
            double[] arr = new double[4] { 0, -5.6, 4, 7 };
            LinearEquation le = new LinearEquation(arr);
            Assert.IsTrue(arr.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void ListConstructorWithList()
        {
            List<double> l = new List<double>() { 5, 7, 2.4, -78, 3 };
            LinearEquation le = new LinearEquation(l);
            Assert.IsTrue(l.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void ListConstructorWithEmptyCollection()
        {
            double[] arr = new double[] { };
            LinearEquation le = new LinearEquation(arr);
            Assert.IsTrue(new double[] { 0, 0 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void ListConstructorWithOneElement()
        {
            double[] arr = new double[] { 5 };
            LinearEquation le = new LinearEquation(arr);
            Assert.IsTrue(new double[] { 5, 0 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void LinearEquationConstructor()
        {
            double[] arr = new double[4] { 0, -5.6, 4, 7 };
            LinearEquation le1 = new LinearEquation(arr);
            LinearEquation le2 = new LinearEquation(le1);
            Assert.IsTrue(((double[])le1).SequenceEqual((double[])le2));
        }
        [TestMethod]
        public void IntConstructor()
        {
            int n = 3;
            LinearEquation le = new LinearEquation(n);
            Assert.IsTrue(new double[] { 0, 0, 0 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void IntConstructorWithZero()
        {
            int n = 0;
            LinearEquation le = new LinearEquation(n);
            Assert.IsTrue(new double[] { 0, 0 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        public void IntConstructorWithOne()
        {
            int n = 1;
            LinearEquation le = new LinearEquation(n);
            Assert.IsTrue(new double[] { 0, 0 }.SequenceEqual((double[])le));
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void IntConstructorWithNegativeArgument()
        {
            int n = 1;
            LinearEquation le = new LinearEquation(n);
            Assert.Equals(typeof(ArgumentException), new LinearEquation(n));
        }
    }
}
