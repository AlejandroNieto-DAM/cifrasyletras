#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "diccionario.h"
#include "bolsaletras.h"

using namespace std;

int main(int argc, char * argv[]){

  if(argc != 4){
    cout << "Los parametros son:"<< endl;
    cout <<"1.- El fichero diccionario" << endl;
    cout <<"2.- El fichero con letras aceptables" << endl;
    cout <<"3.- El fichero de salida" << endl;
    return 0;
  }

    ifstream ifDic(argv[1]),
             ifLet(argv[2]),
             ifSal(argv[3]);
    //Todo este segmento es una forma mas resumida de mirar si los archivos se pueden leer.
    ifstream *ifPunt[3] = {&ifDic, &ifLet, &ifSal};
    for (int i = 0; i < 3; i++)
      if(!(*ifPunt[i])){
        cout << "No puedo abrir el fichero " << argv[i+1] << endl;
        return 0;
      }
    //Creamos un mapa con letras y numero de veces que aparecen las letras
    map<char,int> caracteres;
    map<char,int>::iterator it;
    string line;
    while (getline(ifLet, line)){
      caracteres[line[0]] = 0;
    }
    double totalChar = 0;
    while (getline(ifDic, line)){
      for (int i = 0; i < line.length(); i++){
        if ((it = caracteres.find(line[i])) != caracteres.end()){
          caracteres[line[i]] += 1;
          totalChar++;
        }
      }
    }
    int puntos, frecuenciaMax = 0;
    for (it = caracteres.begin(); it != caracteres.end(); ++it)
      if (it->second > frecuenciaMax)
        frecuenciaMax = it->second;

    cout << frecuenciaMax << endl;
    for (it = caracteres.begin(); it != caracteres.end(); ++it){
      //sistema de puntos aun no estoy seguro
      puntos = 10 - ((it->second / frecuenciaMax) * 10);
      cout << it->first << " aparece " << it->second << " veces, con " << puntos << " puntos." << endl;
    }


    return 0;
}
/**
What this needs to do:
  read every line


#letras
a
b
c
d
e
f
.
.
.
z

*/
