#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "bolsaletras.h"

using namespace std;

int main(int argc, char * argv[]){
    if(argc != 2){
        cout << "Los parametros son:"<< endl;
        cout <<"1.- El fichero con las letras";
        return 0;
    }

    ifstream f(argv[1]);
    if(!f){
        cout << "No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }
    
    BolsaLetras D;
    cout << "Cargando letras..." << endl;
    f>>D;
    
    cout << "Leido el letras..." << endl;
    cout << D;

}