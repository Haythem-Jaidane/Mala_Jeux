prog: fml.o main.o 
	gcc fml.o main.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
fml.o: fml.c
	gcc -c fml.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
