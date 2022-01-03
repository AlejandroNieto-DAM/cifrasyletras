
#include <iostream>
#include <list>
#include "bolsaletras.h"
#include <sstream> 
#include <string>


using namespace std;


void ConjuntoLetras::insertarLetra(Letra l){
	bolsa.push_back(l);
}

istream & operator>>(istream & is, BolsaLetras &D){
    
    string line;
    getline(is, line);

    while (getline(is, line)) {

    	istringstream iss(line);
	    string token;

	    string::size_type sz;   // alias of size_t

		getline(iss, token, '\t');

	    char caracter = (char) token[0];
	    //cout << "Letra: " << caracter << "\t";

		getline(iss, token, '\t');

	    int apariciones = stoi (token,&sz);
	    //cout << "Apariciones: " << apariciones << "\t";

		getline(iss, token, '\t');

	    int valor = stoi (token,&sz);
	    //cout << "Valor: " << valor << endl;

	    Letra l(caracter, apariciones, valor);

	    D.insertarLetra(l);

    }
    
    return is;
    
}

ostream & operator<<(ostream & os, BolsaLetras &D){

	//cout << "Cout de bolsaLetras"  << endl;
	
    BolsaLetras::iterator it;
    for(it = D.begin(); it != D.end(); ++it){
        cout << (*it).getCaracter() << " " << (*it).getApariciones() << " " <<  (*it).getPuntuacion() << endl;
    }
    
    return os;
}