#pragma once
class Indexer
{
private:
	double* array;
	int firstIndex, lastIndex;
public:
	Indexer(const double* array, int firstIndex, int length);
	int Length();
	double operator[] (int index);
	const double operator[] (int index) const;
};