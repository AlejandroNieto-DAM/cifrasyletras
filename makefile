
#visibildad - compatibilidad de tipos (peso importante) - 3ra pregunta de otra cosa - pregunta de resolver

usoBolsa: usoBolsa.cpp bolsaletras.cpp
	g++ -std=c++11 -o usobolsa usobolsa.cpp bolsaletras.cpp

ub: usoBolsa
	./usobolsa ../adicional/letras.txt

usoDiccionario: testDiccionario.cpp diccionario.cpp
	g++ -std=c++11 -o usoDiccionario testDiccionario.cpp diccionario.cpp

ud: usoDiccionario
	./usoDiccionario ../adicional/diccionario1.txt

