#programa a
a.out: Pagina.o TablaHash.o Arbol.o DicPaginas.o Interprete.o main.o
	g++ Pagina.o TablaHash.o Arbol.o DicPaginas.o Interprete.o main.o

#Pagina
Pagina.o: Pagina.cpp Pagina.h
	g++ -c Pagina.cpp

#TablaHash
TablaHash.o : TablaHash.cpp TablaHash.h Pagina.h
	g++ -c TablaHash.cpp
	
#Arbol
Arbol.o : Arbol.cpp Arbol.h Pagina.h
	g++ -c Arbol.cpp

#DicPaginas
DicPaginas.o: DicPaginas.cpp DicPaginas.h TablaHash.h Arbol.h Pagina.h
	g++ -c DicPaginas.cpp

#Interprete
Interprete.o: Interprete.cpp Interprete.h Pagina.h TablaHash.h Arbol.h DicPaginas.h
	g++ -c Interprete.cpp

#main
main.o: main.cpp Pagina.h TablaHash.h Arbol.h DicPaginas.h Interprete.h
	g++ -c main.cpp

#limpiar
clean: 
	rm -f Pagina.o TablaHash.o Arbol.o DicPaginas.o Interprete.o main.o a.out