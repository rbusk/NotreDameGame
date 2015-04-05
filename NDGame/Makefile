#Object files:
OBJ =  main.o LTexture.o SDLClass.o OpeningScreen.o StaticScreen.o GraduatingScreen.o Sprite.o Background.o

# Header files:
HDR = LTexture.h SDLClass.h OpeningScreen.h StaticScreen.h GraduatingScreen.h Sprite.h Background.h

# Libraries
LIBS = `pkg-config --cflags --libs sdl2 SDL2_image SDL2_ttf`

# Executable
EXEC = main.out

# One rule to rule them all
all: $(EXEC)


# Compile
CPP = g++ -c -o $@ $<
LINK = ${LIBS}
CXX = g++ -o $@

# Rules
%.o : %.cpp ${HDRS}
	${CPP}

# Executable rule
$(EXEC) : ${OBJ}
	${CXX} ${OBJ} ${LINK}

# Cleaning
clean:
	rm *.o $(EXEC)

