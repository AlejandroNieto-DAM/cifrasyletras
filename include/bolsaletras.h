#ifndef __BolsaLetras_h_
#define __BolsaLetras_h_

#include <iostream>
#include <vector>

using namespace std;

class BolsaLetras {

    private:
    
        vector<char> caracteres;

    public:

        /**
         * @brief Inserta un nuevo caracter a la bolsa de caracteres
         * 
         * @param c es el nuevo caracter que se añadira a la bolsa
         * @param veces es el numero de veces que quedara añadido el caracter
         */
        void insertarCaracter(char c, int veces);

        /**
         * @brief Desordena el vector de caracteres
         * 
         */
        void shuffleBolsa();

        /**
         * @brief Metodo que obtiene el numeroDeLetras de caracteres de forma aleatoria
         * y los almacena en un vector que devuelve
         * 
         * @param numeroDeLetras es el numero de letras que queremos obtener de forma aleatoria
         * @return vector<char> es el vector resultante con los caracteres almacenados que han sido escogidos
         */
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

