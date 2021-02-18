Makefile: main.cpp Base.cpp Secuencia.cpp Base.hpp Secuencia.hpp 
	g++ -o main main.cpp -lm -Wall
	g++ -o Base Base.cpp -lm -Wall
	g++ -o Secuencia Secuencia.cpp -lm -Wall
