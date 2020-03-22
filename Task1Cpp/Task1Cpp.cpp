#include "Indexer.h"

int main() {
    Indexer i = Indexer(new double[3]{ 1, 2, 3 }, 1, 2);
    int k = i.Length();
    double b = i[0];
    return 0;
}
