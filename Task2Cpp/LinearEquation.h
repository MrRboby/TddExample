#pragma once
#include <vector>
#include <string>

class LinearEquation
{
private:
	std::vector<double> coefficients;
public:
	LinearEquation(std::string str);
	LinearEquation(std::vector<double> vec);
	LinearEquation(double* arr, int size);
	LinearEquation(LinearEquation& le);
	LinearEquation(int count);
	void FillByDuplicates(double number);
	void FillByRandom(double minValue, double maxValue, int seed);
	void FillByRandom(double minValue, double maxValue);
	int GetDegree();
	friend const LinearEquation operator+(const LinearEquation& le1, const LinearEquation& le2);
	friend const LinearEquation operator-(const LinearEquation& le1, const LinearEquation& le2);
	friend const LinearEquation operator*(const LinearEquation& le, const double k);
	friend const LinearEquation operator*(const double k, const LinearEquation& le);
	friend const LinearEquation operator-(const LinearEquation& le);
	friend const bool operator==(const LinearEquation& le1, const LinearEquation& le2);
	friend const bool operator!=(const LinearEquation& le1, const LinearEquation& le2);
	operator bool() const;
	operator std::vector<double>() const;
	const double& operator[] (const int index) const;
	operator std::string() const;

};

