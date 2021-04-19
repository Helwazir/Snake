# M4OEP-Graphics2-helwazir
Created by Hamzah Elwazir
# Snake
This is a simple recreation of the classic game Snake built using C++. Use the arrow keys to maneuver the snake around
the screen and eat as many nodes of food as you can to build up your score. If your snake goes out of bounds or 
intersects with itself it's game over. Try and get the highest score you can. 


# Setup
In order to run this program FreeGLUT must be installed and set up in the project.
#### Setup on Mac:
- No additional setup required on OSX.
#### Setup on Linux:
- Use the CMakeLists-Linux.txt file
#### Setup on PC:
- Dowload FreeGLUT from `http://freeglut.sourceforge.net/index.php#download` and add the `include/` and `lib/` folders
to `C:/Program Files/Common Files/freeglut/`. If the directory does not exist then create it.
- Add `freeglut.dll` from `freeglue/bin/` to the cmake-build-debug folder.
 
# Keyboard and Mouse Commands
This program uses the arrow keys to change the direction that the snake is moving in. In addition, the 'esc' key can
be pressed at any time in order to exit the program. No mouse commands are recognized by the program.
