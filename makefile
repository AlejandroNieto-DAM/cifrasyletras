
#visibildad - compatibilidad de tipos (peso importante) - 3ra pregunta de otra cosa - pregunta de resolver

usoConjunto: usoBolsa.cpp conjuntoletras.cpp
	g++ -std=c++11 -o usoConjunto usobolsa.cpp conjuntoletras.cpp

uc: usoConjunto
	./usoConjunto ../adicional/letras.txt

usoDiccionario: testDiccionario.cpp diccionario.cpp
	g++ -std=c++11 -o usoDiccionario testDiccionario.cpp diccionario.cpp

ud: usoDiccionario
	./usoDiccionario ../adicional/diccionario1.txt

letras: main.cpp diccionario.cpp conjuntoletras.cpp bolsaletras.cpp
	g++ -o letras main.cpp conjuntoletras.cpp diccionario.cpp bolsaletras.cpp

exe_p: letras
	./letras ../adicional/diccionario1.txt ../adicional/letras.txt 20 P

exe_l: letras
	./letras ../adicional/diccionario1.txt ../adicional/letras.txt 20 L