#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "../Task2Cpp/LinearEquation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearEquationTestCpp
{
	TEST_CLASS(LinearEquationTestCpp) {
	public:
		
		TEST_METHOD(StringConstructor) {
			std::string s = "1 1,5 2,6 -4 89 13,4";
			std::vector<double> res = { 1, 1.5, 2.6, -4, 89, 13.4 };
			LinearEquation le = LinearEquation(s);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(StringConstructorWithEmptyString) {
			std::string s = "";
			std::vector<double> res = { 0, 0 };
			LinearEquation le = LinearEquation(s);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(StringConstructorWithOneElement) {
			std::string s = "2";
			std::vector<double> res = { 2, 0 };
			LinearEquation le = LinearEquation(s);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(StringConstructor) {
			std::string s = "1 g 2.25 -5.7 helloworld 3 k";
			Assert::ExpectException<std::invalid_argument>([&] { LinearEquation(s); });
		}
		TEST_METHOD(VectorConstructor) {
			std::vector<double> input = { 0, -5.6, 4, 7 };
			std::vector<double> res = { 0, -5.6, 4, 7 };
			LinearEquation le = LinearEquation(input);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(ArrayConstructor) {
			double* input = new double[4] { 0, -5.6, 4, 7 };
			std::vector<double> res = { 0, -5.6, 4, 7 };
			LinearEquation le = LinearEquation(input, 4);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(VectorConstructorWithEmptyVector) {
			std::vector<double> input = { };
			std::vector<double> res = { 0, 0 };
			LinearEquation le = LinearEquation(input);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(VectorConstructorWithOneElement) {
			std::vector<double> input = { 1 };
			std::vector<double> res = { 1, 0 };
			LinearEquation le = LinearEquation(input);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(ArrayConstructorWithOneElement) {
			double* input = new double[1]{ 2 };
			std::vector<double> res = { 2, 0 };
			LinearEquation le = LinearEquation(input, 1);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(LinearEquationConstructor) {
			std::vector<double> input = { 5, 7, 2.4, -78, 3 };
			std::vector<double> res = { 5, 7, 2.4, -78, 3 };
			LinearEquation le1 = LinearEquation(input);
			LinearEquation le2 = LinearEquation(le1);
			Assert::IsTrue(res == (std::vector<double>)le2);
		}
		TEST_METHOD(IntConstructor) {
			int count = 3;
			std::vector<double> res = { 0, 0, 0 };
			LinearEquation le = LinearEquation(count);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(IntConstructorWithZero) {
			int count = 0;
			std::vector<double> res = { 0, 0 };
			LinearEquation le = LinearEquation(count);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(IntConstructorWithOne) {
			int count = 1;
			std::vector<double> res = { 0, 0 };
			LinearEquation le = LinearEquation(count);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(IntConstructorWithNegativeArgument) {
			int count = -1;
			Assert::ExpectException<std::invalid_argument>([&]{ LinearEquation(count); });
		}
		TEST_METHOD(FillByDuplicates) {
			int count = 4;
			std::vector<double> res = { 7.3, 7.3, 7.3, 7.3 };
			LinearEquation le = LinearEquation(count);
			le.FillByDuplicates(7.3);
			Assert::IsTrue(res == (std::vector<double>)le);
		}
		TEST_METHOD(FillByRandomWithMinMoreThanMaxArguments) {
			int count = 4;
			LinearEquation le = LinearEquation(count);
			Assert::ExpectException<std::invalid_argument>([&] { le.FillByRandom(100, 10); });
		}
		TEST_METHOD(FillByRandomWithEqualSeeds) {
			int count = 3;
			LinearEquation le1 = LinearEquation(count);
			LinearEquation le2 = LinearEquation(count);
			le1.FillByRandom(-5, 10, 100);
			le2.FillByRandom(-5, 10, 100);
			Assert::IsTrue((std::vector<double>)le1 == (std::vector<double>)le2);
		}
		TEST_METHOD(GetDegree) {
			std::vector<double> input = { 1, 2, 3 };
			LinearEquation le = LinearEquation(input);
			Assert::AreEqual(2, le.GetDegree());
		}
		TEST_METHOD(GetDegreeWithZeros) {
			std::vector<double> input = { 1, 2, 3, 0, 0 };
			LinearEquation le = LinearEquation(input);
			Assert::AreEqual(2, le.GetDegree());
		}
		TEST_METHOD(AdditionWithSameCountOfCoefficients) {
			std::vector<double> input1 = { 1, 2, 3 };
			std::vector<double> input2 = { 4, 5, 6 };
			std::vector<double> result = { 5, 7, 9 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(result == (std::vector<double>)(le1 + le2));
		}
		TEST_METHOD(AdditionWithDifferentCountOfCoefficients) {
			std::vector<double> input1 = { 1, -5, 3, 7 };
			std::vector<double> input2 = { 4, 5, 6 };
			std::vector<double> result = { 5, 0, 9, 7 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(result == (std::vector<double>)(le1 + le2));
		}
		TEST_METHOD(SubstractionWithSameCountOfCoefficients) {
			std::vector<double> input1 = { 5, 2, 0 };
			std::vector<double> input2 = { 1, 5, 1 };
			std::vector<double> result = { 4, -3, -1 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(result == (std::vector<double>)(le1 - le2));
		}
		TEST_METHOD(SubstractionWithDifferentCountOfCoefficients) {
			std::vector<double> input1 = { 4, 5, 3};
			std::vector<double> input2 = { 1, 5, 6, 8 };
			std::vector<double> result = { 3, 0, -3, -8 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(result == (std::vector<double>)(le1 - le2));
		}
		TEST_METHOD(LeftMultiplication) {
			std::vector<double> input = { 4, 5, 3 };
			std::vector<double> result = { 8, -10, 6 };
			LinearEquation le = LinearEquation(input);
			double k = 2;
			Assert::IsTrue(result == (std::vector<double>)(k * le));
		}
		TEST_METHOD(RightMultiplication) {
			std::vector<double> input = { 4, 5, 3 };
			std::vector<double> result = { 8, -10, 6 };
			LinearEquation le = LinearEquation(input);
			double k = 2;
			Assert::IsTrue(result == (std::vector<double>)(le * k));
		}
		TEST_METHOD(RightMultiplication) {
			std::vector<double> input = { 2, 0, -4 };
			std::vector<double> result = { -2, 0, 4 };
			LinearEquation le = LinearEquation(input);
			Assert::IsTrue(result == (std::vector<double>)(-le));
		}
		TEST_METHOD(EqualityWithSameCountOfCoefficients) {
			std::vector<double> input1 = { 1, 2, 3 };
			std::vector<double> input2 = { 1, 2, 3 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(le1 == le2);
		}
		TEST_METHOD(EqualityWithDifferentCountOfCoefficients) {
			std::vector<double> input1 = { 1, 2, 3 };
			std::vector<double> input2 = { 1, 2, 3, 0, 0 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(le1 == le2);
		}
		TEST_METHOD(Inequality) {
			std::vector<double> input1 = { 1, 2, 3 };
			std::vector<double> input2 = { 1, 6, 3 };
			LinearEquation le1 = LinearEquation(input1);
			LinearEquation le2 = LinearEquation(input2);
			Assert::IsTrue(le1 != le2);
		}
		TEST_METHOD(TrueLinearEquation) {
			std::vector<double> input = { 1, 2, 1 };
			LinearEquation le = LinearEquation(input);
			Assert::IsTrue((bool)le);
		}
		TEST_METHOD(FalseLinearEquation) {
			std::vector<double> input = { 2, 0, 0 };
			LinearEquation le = LinearEquation(input);
			Assert::IsFalse((bool)le);
		}
		TEST_METHOD(Coefficient) {
			std::vector<double> input = { 2, 3, 1 };
			LinearEquation le = LinearEquation(input);
			Assert::AreEqual((double)3, le[1]);
		}
		TEST_METHOD(CoefficientOutOfRange) {
			std::vector<double> input = { 2, 3, 1, 0, 0, 0 };
			LinearEquation le = LinearEquation(input);
			Assert::ExpectException<std::out_of_range>([&] {le[4]; });
		}
		TEST_METHOD(ToString) {
			std::vector<double> input = { 2, 1, 4 };
			std::string result = "4x2+1x1+2=0";
			LinearEquation le = LinearEquation(input);
			Assert::AreEqual(result, (std::string)le);
		}
		TEST_METHOD(ToStringWithMinus) {
			std::vector<double> input = { 2, -1, 4 };
			std::string result = "4x2-1x1+2=0";
			LinearEquation le = LinearEquation(input);
			Assert::AreEqual(result, (std::string)le);
		}
		TEST_METHOD(ToStringWithZeroArgument) {
			std::vector<double> input = { 2, 1, 0, 4 };
			std::string result = "4x3+1x1+2=0";
			LinearEquation le = LinearEquation(input);
			Assert::AreEqual(result, (std::string)le);
		}
	};
}
