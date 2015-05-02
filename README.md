#NotreDameGame
CSE 20212 Final Project - Notre Dame Game
ND Tailgate Game User Manual

Game Concept and Objective
ND Tailgate is a side scroller game in which the player, a student dedicated to his schoolwork, avoids obstacles and uses powerups to dash past the commotion at Notre Dame on football Saturday and get to the Hesburgh Library.
Special Libraries Needed
The program utilizes the functions of the SDL2 library, so it must be installed first. Besides the base library, the program also uses the following SDL2 extensions:
SDL2_image
Loads image files of all types for use
SDL2_tff
Allows use of TrueType fonts in printing text to screen
SDL2_mixer
Loads and integrates sound into program
Note: the program also uses a couple of function calls exclusive to c++11, and so it is necessary that it also be installed on the system.
How to Build/Compile the Program
Although the program employs quite a few classes, the included Makefile makes compiling easy. Not only does it compile all of the necessary classes, it links to all of the necessary libraries listed above given that they are installed on the machine. 

To compile, simply type make into the command line.
To run, type ./main.out

Concerning c++11, the Makefile automatically flags it for use. Thus if it is properly installed on the system, everything is taken care of in this regard. 

Program Controls and Interactions

Controls
To move the player, use W to jump, A to move left, and D to move right. The space bar shoots a football if the player has one.

Enemies
Different levels spawn different enemies. If the player runs into any of these enemies he dies. The football can be thrown to kill the football player. The enemies are a squirrel, a yellow car, a football player, a soda can, and a red car.



Powerups
There are three different powerups. One is a hamburger, which allows the player to jump higher. Another is a hotdog, which allows the player to run faster. These two powerups have timers and only last a certain amount of time after the player hits them. Finally, there is a football powerup that adds a football to the player’s inventory. If the player has a football in his inventory, the user can press the spacebar to throw it, which can eliminate an oncoming football player. However, the football will not defeat any other enemies; throwing it at cars, squirrels, or cans is a waste.

Levels
Each level increases the frequency of enemies and introduces new, harder enemies. The enemies in level 1 are squirrels, football players, and yellow cars. Level 2 introduces cans and level 3 introduces red cars, which drive towards the player from behind.

Winning
If you makes it through three levels, you win and arrive at the Hesburgh Library.

Known Bugs
Every couple of runs, a background will not load and will instead be replaced with just a white backscreen. The bug is not consistent nor does it throw any errors or warnings so we have not determined the cause. Moreover, a background might be working on one computer, but not working on another at the same time with the same build. 
Every time we load a .png file on a mac, we get the warning: 
libpng warning: iCCP: known incorrect sRGB profile
but the warning does not interfere with the game or loading the images. It simply refers to the fact that the image was built using an older version of libpng and so its sRGB profile is out of date with the latest version of the library.
Very occasionally, the game will slow down significantly, as if it is stuck in a loop or is allocating too much memory for sprites. However, the error has only occurred a few times and, so far, we have not found a cause or a pattern in its occurrences. Once the player dies and the user restarts the game by pressing space, the error is fixed.
