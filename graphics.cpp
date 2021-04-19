#include "graphics.h"
#include "snake.h"
#include <iostream>
#include <vector>
using namespace std;

enum State {PLAY, END};

GLdouble width, height;
int wd;
float R;
float G;
float B;
Snake s;
State screenState = PLAY;
Rect food;



void spawnFood() {
    int xRand = rand() % ((int)width - 20) + 10;
    int yRand = rand() % ((int)height - 20) + 10;

    int x = ceil(xRand / 20) * 20 - 10;
    int y = ceil(yRand / 20) * 20 - 10;

    food = Rect(point2D(x, y), dimensions(20, 20));
    food.setColor(color(0.7, 0.7, 0.7));
}


void init() {
    width = 1000;
    height = 500;
    s = Snake();
    srand(time(0));
    spawnFood();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you're on a Mac running Catalina)

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE


    // Set the color to draw
    // Note: you can change this at any time during the drawing process



//    s.moveAndUpdateBody();
    if (screenState == PLAY) {


        s.draw();
        if (s.getHead().isOverlapping(food)) {
            s.grow();
            spawnFood();
        }
        food.draw();
        if (s.checkLose(width, height)) {
            std::cout << "YOU LOSE!" << std::endl;
            screenState = END;
        }
    }

    if (screenState == END) {
        string message = "You Lose!";
        glColor3f(0, 0, 0);
        glRasterPos2i((width / 2) - (4 * message.length()), height / 2);
        for (const char &letter : message) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }






    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            s.changeDirection(DOWN);
            break;
        case GLUT_KEY_LEFT:
            s.changeDirection(LEFT);
            break;
        case GLUT_KEY_RIGHT:
            s.changeDirection(RIGHT);
            break;
        case GLUT_KEY_UP:
            s.changeDirection(UP);
            break;
    }

//    glutPostRedisplay();
}

void cursor(int x, int y) {

//    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    glutPostRedisplay();
}

void timer(int dummy) {
    s.moveAndUpdateBody();
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);  // 250 is good time
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Dark Green" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(100, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
