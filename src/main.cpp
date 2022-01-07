#include <iostream>
#include <fstream>
#include "diccionario.h"
#include "conjuntoletras.h"
#include "bolsaletras.h"

/**
 * @brief Inicializa el Diccionario con el archivo pasado por parámetros al igual que ConjuntoLetras el cual a su vez inicializa
 * 	los valores que contendra BolsaLetras y obtiene de los argumentos pasados el numero de letras con el que se jugará y el modo de juego
 * @param D es el diccionario que contendra las palabras del fichero pasado en primer lugar por parametros al programa del juego
 * @param CL es el conjunto de letras, esta instancia contendrá la informacion del segundo fichero de texto pasado por argumentos el cual debe
 * 	tener una estructura tal que (A\t17\t1) siendo respectivamente el valor del caracter, apariciones y puntuacion informacion que se guarda en
 *	instancias de la clase Letra las cuales almacena el conjunto de letras.
 * @param BL es la bolsa de letras en ella apareceran los caracteres de cada una de las letras del conjunto de letras tantas veces como apariciones
 * @param numeroLetras es el valor del numero de letras que se mostrarán en pantalla para que el usuario juegue.
 * @param modoJuego es un valor [L, P] el cual nos guiará para obtener la mejor solucion siendo
 * 				P --> la solución con mayor puntuación
 * 				L --> la solución mas larga 
 * @pre Los archivos que se deban de haber pasado tanto el primero como el segundo que son los ficheros de texto deben estar en el formato
 * 	correspondiente para su debido uso ya que si no el programa fallará a la hora de cargarlos
 * @pre el modo de juego debe ser [P, L] si no, se encontrarán errores durante la ejecución del programa
 * @post D quedará rellenado con todas las palabras que se encuentren en el fichero de texto pasado en primer lugar, CL quedará relleno de objetos
 * 	Letra inicializados con cada una de las lineas del fichero pasado en segundo lugar y el resto de variables inicializadas como hemos dicho anteriormente.
 * 
 * */
void setUpGame(char * argv[], Diccionario &D, ConjuntoLetras &CL, BolsaLetras &BL, int &numeroLetras, char &modoJuego);

/**
 * @brief Muestra las soluciones obtenidas dependiendo del modo de juego
 * @param respuestas es un vector de pair el cual contiene el valor de la palabra como respuesta y su valor en puntuacion por si el modo de juego es 'P'
 * @param modoJuego es un valor [L, P] segun el cual se mostrarán las soluciones de una manera u otra
 * 				P --> la solución con mayor puntuación 
 * 				L --> la solución mas larga
 * @post Se mostrará por pantalla cada uno de los valores string del pair y una puntuacion determinada según el modo de juego. 
 * 
 * */
void displaySolutions(vector<pair<string,int> > respuestas, char modoJuego);

/**
 * @brief Obtiene las palabras que se pueden formar a partir del vector de char que se da para realizar el juego.
 * Este metodo se encarga de ir buscando todas las palabras que se pueden formar y obtener su puntuacion
 * 
 * @param D es el diccionario en el que buscaremos las palabras que se pueden formar con letrasJuego
 * @param CL es el conjunto de letras con el cual obtendremos las puntuaciones de las palabras que sean solucion
 * @param numeroLetras es el numero de letras con el que el jugador empezo a jugar. Servirá de tamaño maximo de palabra
 * ya que no habra una palabra mas larga que este numero
 * @param letrasJuego es el vector de char que contiene los caracteres mostrados al usuario para el juego
 * @return vector<pair<string,int> > devuelve este tipo de vector que almacena pair con las palabras solucion y sus respectivas puntuaciones
 * obtenidas del conjunto de letras
 */
vector<pair<string,int> > getSoluciones(Diccionario D, ConjuntoLetras CL, int numeroLetras, vector<char> letrasJuego);

/**
 * @brief Comprueba si una palabra contiene exclusivamente los caracteres usados para el juego 
 * (tambien tiene en cuenta la repeticion ya que si el caracter "a" solo aparece una vez en el juego
 * este no se puede usar dos veces para obtener la palabra "cama" por ejemplo y "cama" seria invalida)
 * 
 * @param palabra es la palabra que queremos comprobar si es valida
 * @param letrasJuego son los caracteres usados para el juego
 * @return true si la palanbra se puede formar a partir de los caracteres usados en el juego
 * @return false si la palabra no puede ser formada a partir de los caracteres usados para el juego
 */
bool comprobarSiUnaPalabraEsValida(string palabra, vector<char> letrasJuego);


int main(int argc, char * argv[]){

	//Comprueba que los argumentos estan de forma correcta
	if(argc != 5){
		cout << "Ejecución invalida!!" << endl;
        cout << "El modo de ejecución es:"<< endl;
        cout << "./letras <diccionario> <letras> <numero_letras> <modo_de_juego>";
        return 0;
    }

	Diccionario D;
	ConjuntoLetras CL;
	BolsaLetras BL;
	int numeroLetras;
	char modoJuego;

	char seguir;
	string respuestaUsuario = "";


	setUpGame(argv, D, CL, BL, numeroLetras, modoJuego);


	do{
		
		vector<char> letrasJuego = BL.getLetrasJuego(numeroLetras);
		vector<char>::iterator it;

		//Mostramos al usuario las letras del juego
		cout << "Las letras son: " << endl;
		for(it = letrasJuego.begin(); it != letrasJuego.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;

		cout << "Dime tu solucion: ";
		cin >> respuestaUsuario;

		cout << endl;
		cout << endl;

		int p;
		//Comprobamos si la respuesta del usuario existe en el Diccionario
		if(D.Esta(respuestaUsuario)){

			//Dependiendo del modo de juego mostraremos una puntuacion u otra
			//Si es modo de juego es P nos basaremos en el conjunto de letras
			//si el modo de juego es L mostraremos como puntuacion la longitud de la palabra
			if(modoJuego == 'P'){
				p = CL.getPuntuacionPalabra(respuestaUsuario);	
			} else {
				p = respuestaUsuario.size();
			}

			cout << respuestaUsuario << " Puntuacion: " << p << endl;
			
	    } else {
	        cout << "No existe esa palabra" << endl;
	    }
	     
	    vector<pair<string,int> > respuestas = getSoluciones(D, CL, numeroLetras, letrasJuego);
	    
	    displaySolutions(respuestas, modoJuego);
	    

	    cout << "¿Quieres seguir jugando [S/N]? ";
	    cin >> seguir; 

    } while(seguir == 'S');
	

    return 0;

}

void setUpGame(char * argv[], Diccionario &D, ConjuntoLetras &CL, BolsaLetras &BL, int &numeroLetras, char &modoJuego){
	ifstream f(argv[1]);
    if(!f){
        cout << "No puedo abrir el diccionario " << argv[1] << endl;
        return;
    }

    ifstream f2(argv[2]);
    if(!f2){
        cout << "No puedo abrir el fichero de letras " << argv[2] << endl;
        return;
    }
    
    f>>D;

    f2>>CL;

    ConjuntoLetras::iterator it;
    for(it = CL.begin(); it != CL.end(); ++it){
    	BL.insertarCaracter((*it).getCaracter(), (*it).getApariciones());
    }

    BL.shuffleBolsa();

    numeroLetras = atoi(argv[3]);

    modoJuego = argv[4][0];

    if (modoJuego == 'P'){
		cout << CL << endl;
	}

}

void displaySolutions(vector<pair<string,int> > respuestas, char modoJuego){
	
	cout << "Mis Soluciones son:" << endl;

	string wordWithMaxValue;
    int lastMaxValue = 0;

    vector<pair<string, int> >::iterator itv3;
    int p;
    for(itv3 = respuestas.begin(); itv3 != respuestas.end(); ++itv3){
    	
    	if(modoJuego == 'P'){
    		p = (*itv3).second;
    	} else {
    		p = (*itv3).first.size();
    	}

    	cout << (*itv3).first << " Puntuacion: " << p << endl;
	 	
	 	if ((*itv3).second > lastMaxValue){
	 		lastMaxValue = (*itv3).second;
			wordWithMaxValue = (*itv3).first;
	 	}
    }
	 
    cout << "Mejor solucion" << endl;
    if(modoJuego == 'L'){
    	cout << (*respuestas.begin()).first << endl;
    } else {
    	cout << wordWithMaxValue << endl;
    }

}


vector<pair<string,int> > getSoluciones(Diccionario D, ConjuntoLetras CL, int numeroLetras, vector<char> letrasJuego){
    vector<pair<string,int> > respuestas;
    vector<string>::iterator itv;
    bool valid = true;

	for(int i = numeroLetras; i > 0; --i){

	    vector<string> palabrasLongitud = D.PalabrasLongitud(i);
		    
	    for(itv = palabrasLongitud.begin(); itv != palabrasLongitud.end(); ++itv){
	    	
	    	valid = comprobarSiUnaPalabraEsValida((*itv), letrasJuego);

	    	if(valid){
	    		pair<string, int> temp;
	    		temp.first = *itv;
	    		temp.second = CL.getPuntuacionPalabra(*itv);
	    		respuestas.push_back(temp);
	    	}
	    	
	    }
	}

	return respuestas;
}

bool comprobarSiUnaPalabraEsValida(string palabra, vector<char> letrasJuego){
	
	bool valid = true;
	vector<char>::iterator res;

	for(int j = 0; j < palabra.size(); ++j){

		res = find(letrasJuego.begin(), letrasJuego.end(), palabra[j]);
		
		if (res == letrasJuego.end()) {
			valid = false;
		} else {
			letrasJuego.erase(res);
		}
	} 

	return valid;
}

