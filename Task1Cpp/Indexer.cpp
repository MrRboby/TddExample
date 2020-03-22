#include "Indexer.h"

Indexer::Indexer(double* array, int firstIndex, int length) {
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

const double& Indexer::operator[] (const int index) const {
	return this->array[index + firstIndex];
}