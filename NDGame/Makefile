#Object files:
OBJ =  main.o LTexture.o SDLClass.o OpeningScreen.o StaticScreen.o GraduatingScreen.o Sprite.o Player.o Background.o Hotdog.o Car1.o Hamburger.o Car2.o Footballer.o Timer.o Football.o FootballPowerup.o SpriteGenerator.o Can.o Squirrel.o Level.o SoundClass.o FinalScreen.o

# Header files:
HDR = LTexture.h SDLClass.h OpeningScreen.h StaticScreen.h GraduatingScreen.h Sprite.h Player.h Background.h Hotdog.h Car1.h Hamburger.h Car2.h Footballer.h Timer.h Football.h FootballPowerup.h SpriteGenerator.h Can.h Squirrel.h Level.h SoundClass.h FinalScreen.h

# Libraries
LIBS = `pkg-config --cflags --libs sdl2 SDL2_image SDL2_ttf SDL2_mixer`

# Executable
EXEC = main.out

# One rule to rule them all
all: $(EXEC)


# Compile
CPP = g++ -std=c++11 -c -o $@ $<
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

