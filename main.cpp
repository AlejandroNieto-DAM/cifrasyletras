
#include <iostream>
#include <stack>
#include <iterator>
#include <vector>
#include "cifras.h"
#include "colors.h"
#include <algorithm>

using namespace std;

int main(){

    cout << FBLU("Bienvenido al juego de las CIFRAS") << endl;
    cout << "Le daremos un set de numeros y podrá " << FRED("usarlos una unica vez") << " para llegar a la solucion correcta!! " << endl;

    Cifras cifrasO;

    vector<int> setOfNumbers = cifrasO.getSetOfSixNumbers();
    vector<int>::iterator it;
    cout << "El conjunto de numeros del que dispones es: " << endl;
    cout << "[";
    for(it = setOfNumbers.begin(); it != setOfNumbers.end() - 1; ++it){
        cout << *it << ",";
    }
    cout << *it << "]" << endl;

    cout << "Y el numero al que te debes acercar es: " << cifrasO.getAleatoryNumber() << endl;

    cout << "Una vez hayas pensado las operaciones ve introduciendolas y pulsa enter (ejem: 8 / 4) " << endl;
    int numberA, numberB;
    char operation;

    vector<int>::iterator p;

    while(!(setOfNumbers.size() == 1){
        cin >> numberA >> operation >> numberB;
        p = find (setOfNumbers.begin(), setOfNumbers.end(), numberA);
        setOfNumbers.erase(p);
        p = find (setOfNumbers.begin(), setOfNumbers.end(), numberB);
        setOfNumbers.erase(p);

        int newNum;
        switch(operation){
            case '+': newNum = numberA + numberB; break;
            case '-': newNum = numberA - numberB; break;
            case '/': newNum = numberA / numberB; break;
            case '*': newNum = numberA * numberB; break;
        }

        setOfNumbers.push_back(newNum);

        cout << "El conjunto de ahora es: " << endl;
        cout << "[";
        for(it = setOfNumbers.begin(); it != setOfNumbers.end() - 1; ++it){
            cout << *it << ",";
        }
        cout << *it << "]" << endl;

    }
    




    

}