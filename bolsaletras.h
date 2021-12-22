#ifndef __BolsaLetras_h_
#define __BolsaLetras_h_


#include "letra.h"
#include <list>
#include <string>


using namespace std;

class BolsaLetras {

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

        
        
};

#endif

