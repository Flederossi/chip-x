chip-x:
	gcc src/main.c -o bin/chip-x -I src/include -L src/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

clean:
	del bin\chip-x.exe

run:
	make
	./bin/chip-x src/images/test.cx