#include "SystemOfLinearEquation.h"
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <cmath>

SystemOfLinearEquation::SystemOfLinearEquation(int size) {
	if (size <= 0) {
		throw std::invalid_argument("Size must be greater than 0");
	}
	this->equations.resize(size);
	for (int i = 0; i < size; i++) {
		this->equations[i] = LinearEquation(2);
	}
}

LinearEquation& SystemOfLinearEquation::operator[] (const int index) {
	if (index < 0 || index >= this->equations.size()) {
		throw std::invalid_argument("Index must be greater than 0 and less than count of equations");
	}
	return this->equations[index];
}

void SystemOfLinearEquation::ToTriangular() {
	std::sort(this->equations.begin(), this->equations.end(), [](LinearEquation x, LinearEquation y) { return x.GetDegree() > y.GetDegree(); });
	int maxDegree = this->equations[0].GetDegree(),
		degreeLimit = std::max(maxDegree - (int)this->equations.size() + 1, 1),
		numberOfEquation = 0;
	for (int d = maxDegree; d >= degreeLimit; d--) {
		if (this->equations[numberOfEquation].GetDegree() < d) {
			continue;
		}
		for (int i = numberOfEquation + 1; i < this->equations.size(); i++) {
			if (this->equations[i].GetDegree() >= d) {
				this->equations[i] = this->equations[i] - this->equations[numberOfEquation] * (this->equations[i][d] / this->equations[numberOfEquation][d]);
			}
		}
		std::sort(this->equations.begin(), this->equations.end(), [](LinearEquation x, LinearEquation y) { return x.GetDegree() > y.GetDegree(); });
		numberOfEquation += 1;
	}
}

const std::vector<double> SystemOfLinearEquation::Solve() {
	SystemOfLinearEquation sle = SystemOfLinearEquation(this->equations.size());
	for (int i = 0; i < sle.equations.size(); i++) {
		sle.equations[i] = LinearEquation(this->equations[i]);
	}
	sle.ToTriangular();
	for (int i = 0; i < sle.equations.size(); i++) {
		if (!(bool)sle.equations[i]) {
			throw std::logic_error("System contains contradictory equations");
		}
	}
	std::vector<double> result;
	result.resize(sle.equations[0].GetDegree());
	std::fill(result.begin(), result.end(), std::numeric_limits<double>::infinity());
	for (int i = sle.equations.size() - 1; i >= 0; i--) {
		if (sle.equations[i].GetDegree() == 0 || !std::isinf(result[sle.equations[i].GetDegree() - 1])) {
			continue;
		}
		result[sle.equations[i].GetDegree() - 1] = -sle.equations[i][0];
		for (int j = sle.equations[i].GetDegree() - 1; j >= 1; j--) {
			if (!std::isinf(result[j - 1])) {
				result[sle.equations[i].GetDegree() - 1] -= sle.equations[i][j] * result[j - 1];
			}
			else {
				result[sle.equations[i].GetDegree() - 1] = std::numeric_limits<double>::infinity();
				break;
			}
		}
		result[sle.equations[i].GetDegree() - 1] /= sle.equations[i][sle.equations[i].GetDegree()];
	}
	return result;
}

SystemOfLinearEquation::operator std::string() const {
	std::string result = "";
	for (int i = 0; i < this->equations.size(); i++) {
		result += (std::string)this->equations[i] + "\n";
	}
	return result;
}