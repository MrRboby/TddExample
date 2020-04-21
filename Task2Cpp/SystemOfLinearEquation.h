#pragma once
#include <vector>
#include "LinearEquation.h"
class SystemOfLinearEquation
{
private:
	std::vector<LinearEquation> equations;
public:
	SystemOfLinearEquation(int size);
	LinearEquation& operator[] (const int index);
	void ToTriangular();
	const std::vector<double> Solve();
	operator std::string() const;
};

