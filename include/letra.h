#ifndef __Letra_h__
#define __Letra_h__

class Letra {
    private:
        char caracter;
        int apariciones;
        int puntuacion;
    
    public:
        
        Letra(char caracter, int apariciones, int puntuacion){
            this->caracter = caracter;
            this->apariciones = apariciones;
            this->puntuacion = puntuacion;
        }
    
        inline char getCaracter() const { return this->caracter; };
        inline int getApariciones() const { return this->apariciones; };
        inline int getPuntuacion() const { return this->puntuacion; };
    
};

#endif
