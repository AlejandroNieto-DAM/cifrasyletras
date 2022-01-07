#ifndef __Letra_h__
#define __Letra_h__

class Letra {
    private:
        char caracter;
        int apariciones;
        int puntuacion;
    
    public:
        
        /**
         * @brief Contructor por parametros del objeto Letra
         * 
         * @param caracter es el valor de caracter asociado al objeto
         * @param apariciones es el numero de apariciones que el caracter se repite en el diccionario
         * @param puntuacion es la puntuacion asociada en base a las apariciones y frecuencia del caracter en el diccionario
         */
        Letra(char caracter, int apariciones, int puntuacion){
            this->caracter = caracter;
            this->apariciones = apariciones;
            this->puntuacion = puntuacion;
        }
    
        /**
         * @brief Get del valor del parámetro caracter de la instacia
         * 
         * @return char
         */
        inline char getCaracter() const { return this->caracter; };

        /**
         * @brief Get del numero de apariciones de el caracter
         * 
         * @return int
         */
        inline int getApariciones() const { return this->apariciones; };

        /**
         * @brief Get del valor de la puntuación del caracter de la instacia
         * 
         * @return int
         */
        inline int getPuntuacion() const { return this->puntuacion; };
    
};

#endif
