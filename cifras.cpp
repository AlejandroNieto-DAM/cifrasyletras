#include "cifras.h"
#include <iostream>
#include <vector>
using namespace std;

Cifras::Cifras(){
    this->numberToSolve = 0;
}

Cifras::~Cifras(){
    this->numberToSolve = 0;
    for(int i = 0; i < sizeof(this->defaultSetNumbers)/sizeof(int); i++){
        this->defaultSetNumbers[i] = 0;
    }
}

vector<int> Cifras::getSetOfSixNumbers(){
    
    vector<int> setOfNumbers;
    
    for(int i = 0; i < 6; i++){
        int num=rand()%(14-0+1)+0;
        setOfNumbers.push_back(this->defaultSetNumbers[num]);
    }

    return setOfNumbers;

}

int Cifras::getAleatoryNumber(){
    int num=rand()%(1000-100+1)+100;
    return num;
}

int Cifras::compareIfItsCorrect(int num){
    return 1;
}