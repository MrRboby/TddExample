#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <string>
#include <vector>
#include "../Task2Cpp/SystemOfLinearEquation.h"
#include "../Task2Cpp/SystemOfLinearEquation.cpp"
#include "../Task2Cpp/LinearEquation.h"
#include "../Task2Cpp/LinearEquation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SystemOfLinearEquationTestCpp
{
	TEST_CLASS(SystemOfLinearEquationTestCpp)
	{
	public:
		
		TEST_METHOD(Constructor) {
			int size = 2;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			std::string result = "0=0\n0=0\n";
			Assert::AreEqual(result, (std::string)sle);
		}
		TEST_METHOD(ConstructorWithNegativeArgument) {
			Assert::ExpectException<std::invalid_argument>([] { SystemOfLinearEquation(-2); });
		}
		TEST_METHOD(Get) {
			int size = 1;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			std::string result = "0=0";
			Assert::AreEqual(result, (std::string)sle[0]);
		}
		TEST_METHOD(GetWithIncorrectArgument) {
			int size = 1;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			Assert::ExpectException<std::invalid_argument>([&] { sle[-4]; });
		}
		TEST_METHOD(SetAndGet) {
			int size = 2;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			sle[0] = LinearEquation("1 2 3");
			std::string result = "3.000000x2+2.000000x1+1.000000=0";
			Assert::AreEqual(result, (std::string)sle[0]);
		}
		TEST_METHOD(SetWithIncorrectArgument) {
			int size = 1;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			Assert::ExpectException<std::invalid_argument>([&] { sle[3] = LinearEquation("1 2 3"); });
		}
		TEST_METHOD(Triangular) {
			int size = 3;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			sle[0] = LinearEquation("-8 -1 1 2");
			sle[1] = LinearEquation("11 2 -1 -3");
			sle[2] = LinearEquation("3 2 1 -2");
			sle.ToTriangular();
			std::string result = "2.000000x3+1.000000x2-1.000000x1-8.000000=0\n0.500000x2+0.500000x1-1.000000=0\n-1.000000x1-1.000000=0\n";
			Assert::AreEqual(result, (std::string)sle);
		}
		TEST_METHOD(Solve) {
			int size = 3;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			sle[0] = LinearEquation("-8 -1 1 2");
			sle[1] = LinearEquation("11 2 -1 -3");
			sle[2] = LinearEquation("3 2 1 -2");
			std::vector<double> result = { -1, 3, 2 };
			Assert::IsTrue(result == sle.Solve());
		}
		TEST_METHOD(SolveWithSameEquations) {
			int size = 4;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			sle[0] = LinearEquation("-8 -1 1 2");
			sle[1] = LinearEquation("11 2 -1 -3");
			sle[2] = LinearEquation("11 2 -1 -3");
			sle[3] = LinearEquation("3 2 1 -2");
			std::vector<double> result = { -1, 3, 2 };
			Assert::IsTrue(result == sle.Solve());
		}
		TEST_METHOD(SolveWithContradictoryEquations) {
			int size = 4;
			SystemOfLinearEquation sle = SystemOfLinearEquation(size);
			sle[0] = LinearEquation("-8 -1 1 2");
			sle[1] = LinearEquation("11 2 -1 -3");
			sle[2] = LinearEquation("3 2 1 -2");
			sle[3] = LinearEquation("4 2 2 -2");
			Assert::ExpectException<std::logic_error>([&] { sle.Solve(); });
		}
	};
}
