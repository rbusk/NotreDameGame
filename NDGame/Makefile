#Object files:
OBJ = LTexture.o SDLClass.o main.o

# Header files:
HDR = LTexture.h SDLClass.h

# Libraries
LIBS = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf

# Executable
EXEC = main.out

# One rule to rule them all
all: $(EXEC)


# Compile
CPP = g++ -c -o $@ $<
LINK = g++ -o $@ ${LIBS}

# Rules
%.o : %.cpp ${HDRS}
	${CPP}

# Executable rule
$(EXEC) : ${OBJ}
	   ${LINK} ${OBJ}

# Cleaning
clean:
	rm *.o $(EXEC)

