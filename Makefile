ALL:
	gcc *.c -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -g
	./prog