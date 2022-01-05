
usoConjunto: src/usoconjunto.cpp src/conjuntoletras.cpp
	g++ -std=c++11 -o bin/usoConjunto src/usoconjunto.cpp src/conjuntoletras.cpp

uc: usoConjunto
	bin/./usoConjunto datos/letras.txt

usoDiccionario: src/testDiccionario.cpp src/diccionario.cpp
	g++ -std=c++11 -o bin/usoDiccionario src/testDiccionario.cpp src/diccionario.cpp

ud: usoDiccionario
	bin/./usoDiccionario datos/diccionario1.txt

letras: src/main.cpp src/diccionario.cpp src/conjuntoletras.cpp src/bolsaletras.cpp
	g++ -o bin/letras src/main.cpp src/conjuntoletras.cpp src/diccionario.cpp src/bolsaletras.cpp

exe_p: letras
	bin/./letras datos/diccionario1.txt datos/letras.txt 20 P

exe_l: letras
	bin/./letras datos/diccionario1.txt datos/letras.txt 20 L