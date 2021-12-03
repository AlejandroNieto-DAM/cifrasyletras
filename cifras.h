
#ifndef cifras_h
#define cifras_h

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Cifras {
    private:
        int defaultSetNumbers[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};
        int numberToSolve;

    public:

        Cifras();
        ~Cifras();

        //Duelve el conjunto de numeros que la persona debe tratar
        vector<int> getSetOfSixNumbers();

        //Comprueba si el numero que se ha pasado (una vez ya procesado) se puede conseguir
        //o hay una solucion mas cercana
        int compareIfItsCorrect(int number);

        //Devuelve el aleatorio de 3 cifras
        int getAleatoryNumber();

};

#endif