
output: main.o estudiante.o beneficio.o
	g++ -o main main.o estudiante.o beneficio.o

main.o: main.cpp
	g++ -c main.cpp

estudiante.o: estudiante.cpp estudiante.h
	g++ -c estudiante.cpp estudiante.h

beneficio.o: beneficio.cpp beneficio.h
	g++ -c beneficio.cpp beneficio.h

clear: 
	rm *.o *.h.gch main	