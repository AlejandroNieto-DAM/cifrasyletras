#include "diccionario.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Diccionario::Diccionario(){
    
}

bool Diccionario::insertarPalabra(string palabra){
    return this->datos.insert(palabra).second;
}

int Diccionario::size() const {
    return this->datos.size();
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
    set<string>::iterator it;
    vector<string> salida;
    
    for(it = this->datos.begin(); it != this->datos.end(); ++it){
        if((*it).length() == longitud){
            salida.push_back(*it);
        }
    }
    
    return salida;
}

bool Diccionario::Esta(string palabra){
    return this->datos.find(palabra) != this->datos.end();
}

istream & operator>>(istream & is,Diccionario &D){
    string line;
    while (getline(is, line)) {
        D.insertarPalabra(line.c_str());
    }
    
    return is;
    
}

ostream & operator<<(ostream & os, const Diccionario &D){
    Diccionario::iterator it;
    for(it = D.begin(); it != D.end(); ++it){
        cout << *it << endl;
    }
    
    return os;
}



