#ifndef __ConjuntoLetras_h_
#define __ConjuntoLetras_h_

#include <iostream>
#include <set>
#include "Letra.h"

class ConjuntoLetras {
    
    private:
        list<Letra> bolsa;
    
    public:


        void insertarLetra(Letra l);

        friend istream & operator>>(istream & is, BolsaLetras &D);
        
        friend ostream & operator<<(ostream & os, BolsaLetras &D);

        class iterator{
            public:
                list<Letra >::iterator it;
            
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
            
                friend class BolsaLetras;
        };

        iterator begin() {
            iterator i;
            i.it = this->bolsa.begin();
            return i;
            
        }
    
        iterator end() {
            iterator i;
            i.it = this->bolsa.end();
            return i;
        }

        

}

#endif
