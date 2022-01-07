#ifndef __ConjuntoLetras_h_
#define __ConjuntoLetras_h_

#include <iostream>     
#include <vector>
#include "letra.h"
#include <string>

using namespace std;

class ConjuntoLetras {
    
    private:

        //Vector que almacenará objetos Letra
        vector<Letra> conjunto;

        /**
         * @brief Obtiene la puntuacion de un caracter
         * 
         * @param c es el caracter que queremos buscar en el conjunto para buscar su puntuacion
         * @return int es la puntuacion asociada a una caracter
         */
        int getPuntuacionCaracter(char c);
    
    public:

        /**
         * @brief Inserta un nuevo objeto Letra al conjunto
         * 
         * @param l es el nuevo objeto que se añadira
         */
        void insertarLetra(Letra l);

        /**
         * @brief Calcula la puntuacion de una palabra buscando caracter por caracter en el conjunto
         * 
         * @param palabra es la palabra de la cual queremos saber la puntuacion
         * @return int es el resultado obtenido de la puntuacion de la palabra
         */
        int getPuntuacionPalabra(string palabra);

        /**
         * @brief Lee de un flujo de entrada un diccionario 
         *
         * @param is:flujo de entrada
         * @param D: el objeto donde se realiza la lectura. 
         * @return el flujo de entrada
        **/
        friend istream & operator>>(istream & is,  ConjuntoLetras &D);
        
        /**
         * @brief Escribe en un flujo de salida un diccionario 
         * 
         * @param os:flujo de salida
         * @param D: el objeto diccionario que se escribe 
         * @return el flujo de salida
        **/
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
