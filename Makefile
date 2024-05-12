prog: main.o bg.o game.o 
	gcc game.o  bg.o main.o  -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm
main.o:main.c
	gcc -c main.c -g
bg.o:bg.c 
	gcc -c bg.c -g
game.o:game.c 
	gcc -c game.c -g
clean:
	rm -f*.o prog	
