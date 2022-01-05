#ifndef __BolsaLetras_h_
#define __BolsaLetras_h_

#include <iostream>
#include <vector>

using namespace std;

class BolsaLetras {

    private:
        vector<char> caracteres;

    public:

        void insertarCaracter(char c, int veces);

        void shuffleBolsa();

        vector<char> getLetrasJuego(int numeroDeLetras);

        class iterator{
            public:
                vector<char >::iterator it;
            
                char operator *(){
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
            i.it = this->caracteres.begin();
            return i;
            
        }
    
        iterator end() {
            iterator i;
            i.it = this->caracteres.end();
            return i;
        }
        
        
};

#endif

