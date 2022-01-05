#include <iostream>
#include "bolsaletras.h"
#include <vector>
#include <algorithm>
#include <vector>
#include<random>
#include<chrono>

using namespace std;

void BolsaLetras::insertarCaracter(char c, int veces){
	for(int i = 0; i < veces; i++){
		caracteres.push_back(c);
	}
}

void BolsaLetras::shuffleBolsa(){
	//vector<reference_wrapper<const char> > v(caracteres.begin(), caracteres.end());
    random_device rd;
    mt19937 generator(rd());
    shuffle(caracteres.begin(), caracteres.end(), generator);
    //copy(v.cbegin(), v.cend(), caracteres.begin());
}

vector<char> BolsaLetras::getLetrasJuego(int numeroDeLetras){
	vector<char> letrasJuego;
	for(int i = 0; i < numeroDeLetras; i++){
		int randNum = rand()%(caracteres.size());
		letrasJuego.push_back(caracteres[randNum]);
	}

	return letrasJuego;
}