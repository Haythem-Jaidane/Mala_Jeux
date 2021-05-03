prog: PP.o main.o 
	gcc PP.o main.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
PP.o: PP.c
	gcc -c PP.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
