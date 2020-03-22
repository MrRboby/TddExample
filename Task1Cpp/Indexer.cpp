#include "Indexer.h"
#include <stdexcept>

Indexer::Indexer(double* array, int arrayLength, int firstIndex, int length) {
	if (firstIndex < 0 || length <= 0 || firstIndex + length >= arrayLength)
		throw std::invalid_argument("Incorrect first index or length");
	this->array = array;
	this->firstIndex = firstIndex;
	this->lastIndex = firstIndex + length - 1;
}

int Indexer::Length() {
	return this->lastIndex - this->firstIndex + 1;
}

double& Indexer::operator[] (const int index) {
	return this->array[index + firstIndex];
}