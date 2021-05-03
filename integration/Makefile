jeux: menu_principal.o menu_option.o menu_newgame.o PP.o scrolling.o fml.o collision.o main.o
	gcc main.o menu_principal.o menu_option.o menu_newgame.o PP.o scrolling.o fml.o collision.o -o jeux -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o: main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
menu_principal.o: source/menu_principal.c
	gcc -c source/menu_principal.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
menu_option.o: source/menu_option.c
	gcc -c source/menu_option.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
menu_newgame.o: source/menu_newgame.c
	gcc -c source/menu_newgame.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
PP.o: source/PP.c
	gcc -c source/PP.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
scrolling.o: source/scrolling.c
	gcc -c source/scrolling.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
fml.o: source/fml.c
	gcc -c source/fml.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
collision.o: source/collision.c
	gcc -c source/collision.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
