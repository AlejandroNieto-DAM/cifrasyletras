
#include <iostream>
#include <vector>
#include "conjuntoletras.h"
#include <sstream> 
#include <string>

using namespace std;

void ConjuntoLetras::insertarLetra(Letra l){
	conjunto.push_back(l);
}

int ConjuntoLetras::getPuntuacionCaracter(char c){
	vector<Letra>::iterator it;
	for(it = conjunto.begin(); it != conjunto.end(); ++it){
		if((*it).getCaracter() == c){
			return (*it).getPuntuacion();
		}
	}

	return -1;
}

int ConjuntoLetras::getPuntuacionPalabra(string palabra){
	
	int puntuacion = 0;
	for(int i = 0; i < palabra.size(); i++){
		puntuacion += getPuntuacionCaracter(palabra[i]);
	}

	return puntuacion;
}

istream & operator>>(istream & is, ConjuntoLetras &D){
    
    string line;
    getline(is, line);

    while (getline(is, line)) {

    	istringstream iss(line);
	    string token;

	    string::size_type sz;   // alias of size_t

		getline(iss, token, '\t');

	    char caracter = (char) token[0];

		getline(iss, token, '\t');

	    int apariciones = stoi (token,&sz);

		getline(iss, token, '\t');

	    int valor = stoi (token,&sz);

	    Letra l(caracter, apariciones, valor);

	    D.insertarLetra(l);

    }
    
    return is;
    
}

ostream & operator<<(ostream & os, ConjuntoLetras &D){
	
	cout << "******* Puntuaciones Letras ********" << endl;
    ConjuntoLetras::iterator it;
    for(it = D.begin(); it != D.end(); ++it){
        cout << (*it).getCaracter() << "\t" <<  (*it).getPuntuacion() << endl;
    }
    
    return os;
}