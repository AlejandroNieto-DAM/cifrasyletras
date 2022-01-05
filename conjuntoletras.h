#ifndef __ConjuntoLetras_h_
#define __ConjuntoLetras_h_

#include <iostream>     
#include <vector>
#include "letra.h"
#include <string>

using namespace std;

class ConjuntoLetras {
    
    private:
        vector<Letra> conjunto;
    
    public:

        void insertarLetra(Letra l);

        int getPuntuacionPalabra(string palabra);

        int getPuntuacionCaracter(char c);

        friend istream & operator>>(istream & is,  ConjuntoLetras &D);
        
        friend ostream & operator<<(ostream & os, ConjuntoLetras &D);

        class iterator{
            public:
                vector<Letra >::iterator it;
            
                Letra operator *(){
                    return *it;
                }
            
                iterator & operator ++(){
                    ++it;
                    return *this;
                }
            
                bool operator ==(const iterator &i){
                    return i.it == it;
                }
    
                bool operator !=(const iterator &i){
                    return i.it != it;
                }
            
                friend class ConjuntoLetras;
        };

        iterator begin() {
            iterator i;
            i.it = this->conjunto.begin();
            return i;
            
        }
    
        iterator end() {
            iterator i;
            i.it = this->conjunto.end();
            return i;
        }

        

};

#endif
