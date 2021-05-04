prog: PP.o main.o es.o
	gcc PP.o es.o main.o -o prog -g -lSDL -lSDL_image
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image
PP.o: PP.c
	gcc -c PP.c -g -lSDL -lSDL_image
es.o: es.c
	gcc -c es.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
