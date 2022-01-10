#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "diccionario.h"
#include "bolsaletras.h"

using namespace std;

//Estructura y operaciones para guardar y sortear letras, su cantidad y su puntuacion
struct letra{
  char id;
  int cantidad, puntos;
};

bool compara_cantidad(letra &a, letra &b) {return a.cantidad<b.cantidad;};
bool compara_id(letra &a, letra &b) {return a.id<b.id;};


int main(int argc, char * argv[]){

  if(argc != 4){
    cout << "Los parametros son:"<< endl;
    cout <<"1.- El fichero diccionario" << endl;
    cout <<"2.- El fichero con letras aceptables" << endl;
    cout <<"3.- El fichero de salida" << endl;
    return 0;
  }

    ifstream ifDic(argv[1]),
             ifLet(argv[2]);
    ofstream ofSal(argv[3]);

    if(!ifDic){
      cout << "No puedo abrir el fichero " << argv[1] << endl;
      return 0;
    }
    if(!ifLet){
      cout << "No puedo abrir el fichero " << argv[2] << endl;
      return 0;
    }
    if(!ofSal){
      cout << "No puedo abrir el fichero " << argv[3] << endl;
      return 0;
    }




    //Creamos un vector con letras y numero de veces que aparecen las letras
    vector<letra> caracteres;
    vector<letra>::iterator it;
    letra aux;
    string line;
    bool found;
    //Leemos valores del archivo de letras, cogiendo solo la primera letra de una linea si hay multiples
    while (getline(ifLet, line)){
      aux.id = line[0];
      aux.cantidad = 0;
      aux.puntos  = 0;
      caracteres.push_back(aux);
    }

    //contamos la cantidad de veces que aparece cada letra en el diccionario
    while (getline(ifDic, line)){
      for (int i = 0; i < line.length(); i++){
        found = 0;
        for (int j = 0; j < caracteres.size() || found == 0; j++){
          if(line[i] == caracteres[j].id){
            caracteres[j].cantidad += 1;
            found = 1;
          }
        }
      }
    }

    //eliminamos los que no aparecen ninguna vez
    for (it = caracteres.begin(); it != caracteres.end(); ++it){
      if (it->cantidad == 0){
        caracteres.erase(it);
      }
    }


    //sorteamos segun cantidad para asignar puntuacion
    sort(caracteres.begin(), caracteres.end(), compara_cantidad);
    int cantidad_max = caracteres[caracteres.size()-1].cantidad;

    //asignamos puntuacion
    int punto;
    for (double i = 0; i < caracteres.size(); i++){
      punto = 10 - (caracteres[i].cantidad*10)/(cantidad_max-1);
      if (punto == 0) punto = 1;
      caracteres[i].puntos = punto;
    }
    //sorteamos alfabeticamente para escribir en el archivo
    sort (caracteres.begin(), caracteres.end(), compara_id);

    //escribimos en archivo y pantalla
    ofSal << "#Letra  Cantidad  puntuacion\n";
    for (int i = 0; i < caracteres.size(); i++){
      cout << caracteres[i].id << " aparece " << caracteres[i].cantidad << " veces, con " << caracteres[i].puntos << " puntos." << endl;
      ofSal << caracteres[i].id << "\t" << caracteres[i].cantidad << "\t" << caracteres[i].puntos << "\n";
    }


    return 0;
}
