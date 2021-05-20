m:main2.o perso.o background.o
	gcc  main2.o perso.o background.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -o m -g


main2.o:main2.c
	gcc -c main2.c -g

background.o:background.c
	gcc -c background.c -g

perso.o:perso.c
	gcc -c perso.c -g
