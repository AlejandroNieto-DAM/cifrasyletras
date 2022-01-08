#ifndef __Diccionario_h__
#define __Diccionario_h__
#include <set>
#include <vector>
#include <string>

using namespace std;

class Diccionario{
    private:
        set<string> datos;
    public:
        /**
        @brief Construye un diccionario vacío.
        **/
        Diccionario();

        /**
         * @brief Añade una nueva palabra al diccionario si esta no estaba
         * 
         * @param palabra es la nueva palabra que se quiere añadir 
         * @return true si se ha podido añadir la palabra (no existia en el diccionario)
         * @return false si no se ha podido añadir la palabra (existia en el diccionario)
         */
        bool insertarPalabra(string palabra);

        /**
        @brief Devuelve el numero de palabras en el diccionario
        **/
        int size() const ;
        /**
        @brief Obtiene todas las palabras en el diccionario de un longitud dada
        @param longitud: la longitud de las palabras de salida
        @return un vector con las palabras de longitud especifica en el parametro de entrada
        **/
        vector<string> PalabrasLongitud(int longitud);
        /**
        @brief Indica si una palabra está en el diccionario o no
        @param palabra: la palabra que se quiere buscar
        @return true si la palabra esta en el diccionario. False en caso contrario
        **/
        bool Esta(string palabra);
        /**
        @brief Lee de un flujo de entrada un diccionario @param is:flujo de entrada
        @param D: el objeto donde se realiza la lectura. @return el flujo de entrada
        **/
        friend istream & operator>>(istream & is,Diccionario &D);
        /**
        @brief Escribe en un flujo de salida un diccionario @param os:flujo de salida
        @param D: el objeto diccionario que se escribe @return el flujo de salida
        **/
        friend ostream & operator<<(ostream & os, const Diccionario &D);
        
        
        class iterator{
            public:
                set<string>::iterator it;
            
                string operator *(){
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
            
                friend class Diccionario;
        };

        iterator begin() const {
            iterator i;
            i.it = this->datos.begin();
            return i;
            
        }
    
        iterator end() const {
            iterator i;
            i.it = this->datos.end();
            return i;
        }
    
        
    
};

#endif
