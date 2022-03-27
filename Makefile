SRC = src
BIN = bin
TARGET = tetris
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %, $(BIN)/%, $(notdir $(SOURCE:.c=.o))) 

$(BIN)/%.o : $(SRC)/%.c 
	mkdir -p $(@D)
	gcc -g -Wall -ansi -pedantic -c $< -o $@ 

$(BIN)/$(TARGET) : $(OBJECT)
	gcc -o $@ $^ $(LIBS)

#init.o: src/init.c header/init.h
#		mkdir bin
#		gcc -g -Wall -ansi -pedantic -c src/init.c -o bin/init.o -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
#
#window.o: src/window.c header/window.h
#		gcc -g -Wall -ansi -pedantic -c src/window.c -o bin/window.o -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#texture.o: src/texture.c header/texture.h
#		gcc -g -Wall -ansi -pedantic -c src/texture.c -o bin/texture.o -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#render.o: src/render.c header/render.h
#		gcc -g -Wall -ansi -pedantic -c src/render.c -o bin/render.o -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#event.o: src/event.c header/event.h
#		gcc -g -Wall -ansi -pedantic -c src/event.c -o bin/event.o -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

#tetris: src/main.c bin/init.o bin/window.o bin/texture.o
#		gcc -g -Wall -ansi -pedantic src/main.c bin/init.o bin/window.o bin/texture.o bin/render.o bin/event.o -o bin/tetris -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

run :
		bin/./tetris

clean : 
		rm -r bin 






#TARGET = tetris
#SRC = src
#BIN = bin
#SOURCE = $(wildcard $(SRC)/*.c)
#OBJECT = $(SOURCE:.c=.o)
#
#CC = gcc
#CFLAGS = -g -Wall -ansi -pedantic
#L_SDL = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
#
#$(BIN)/%.o : $(SRC)/%.c
#		@echo "Compiling..."
#		$(CC) $(CFLAGS) -c $< -o $@ $(L_SDL)
#
#$(BIN) : 
#	mkdir $@
#
#$(TARGET) : $(OBJECT)
#		@echo "Linking..."
#		$(CC) $(CFLAGS) -o $@ $^ $(L_SDL) 
#		@echo "Finished!"
#
#run : $(TARGET)
#		./$(TARGET)
#
#clean : 
#		rm -f $(TARGET) $(OBJECT)
