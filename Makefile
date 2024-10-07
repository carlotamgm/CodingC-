################################################################################
## Fichero «Makefile» para los programas de la práctica 6:
## «datos-pruebas», «contar-usos» y «usos-por-usuario»
################################################################################

datos-pruebas:                src/1-datos-pruebas.cpp | bin
	g++ -g -Wall -Wextra      src/1-datos-pruebas.cpp -o bin/datos-pruebas -static

contar-usos:                  build/2-contar-usos.o build/uso-bizi.o build/pedir-nombre-fichero.o  | bin
	g++ -g                    build/2-contar-usos.o build/uso-bizi.o build/pedir-nombre-fichero.o -o bin/contar-usos -static

usos-por-usuario:             build/3-usos-por-usuario.o build/uso-bizi.o build/usuario-bizi.o build/pedir-nombre-fichero.o  | bin
	g++ -g                    build/3-usos-por-usuario.o build/uso-bizi.o build/usuario-bizi.o build/pedir-nombre-fichero.o -o bin/usos-por-usuario -static

build/2-contar-usos.o:        src/2-contar-usos.cpp src/uso-bizi.hpp src/pedir-nombre-fichero.hpp | build
	g++ -g -Wall -Wextra -c   src/2-contar-usos.cpp -o build/2-contar-usos.o 

build/pedir-nombre-fichero.o: src/pedir-nombre-fichero.cpp src/pedir-nombre-fichero.hpp | build
	g++ -g -Wall -Wextra -c   src/pedir-nombre-fichero.cpp -o build/pedir-nombre-fichero.o 

build/uso-bizi.o:             src/uso-bizi.cpp src/uso-bizi.hpp | build
	g++ -g -Wall -Wextra -c   src/uso-bizi.cpp -o build/uso-bizi.o 

build/3-usos-por-usuario.o:	  src/3-usos-por-usuario.cpp src/uso-bizi.hpp src/usuario-bizi.hpp src/pedir-nombre-fichero.hpp | build
	g++ -g -Wall -Wextra -c	  src/3-usos-por-usuario.cpp -o build/3-usos-por-usuario.o 

build/usuario-bizi.o:		  src/usuario-bizi.cpp src/usuario-bizi.hpp | build
	g++ -g -Wall -Wextra -c	  src/usuario-bizi.cpp -o build/usuario-bizi.o 

bin:
	mkdir bin

build:
	mkdir build

clean:
ifeq ($(OS),Windows_NT)
	if exist bin rmdir /S /Q bin
	if exist build rmdir /S /Q build
else
	rm -f build/* bin/*
endif
