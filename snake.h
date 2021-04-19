#ifndef M4OEP_GRAPHICS2_SNAKE_H
#define M4OEP_GRAPHICS2_SNAKE_H

#include <vector>
#include "rect.h"
using std::vector;


enum Direction {LEFT, RIGHT, UP, DOWN};

class Snake {
private:
    dimensions dim = dimensions(20, 20);
    Direction currDirection;
    vector<Rect> body;

public:
    /*
     * Requires: Nothing
     * Modifies: length, body
     * Effects: Initializes length to 1 and populates the snake's body with one body segment(Rect).
     */
    Snake();

    /*
     * Requires: Nothing
     * Modifies: Body
     * Effects: Moves the snake's body in the current direction the snake is heading in. It updates the centers of
     *          each body segment(Rect).
     */
    void moveAndUpdateBody();

    /*
     * Requires: The direction to begin moving
     * Modifies: currDirection
     * Effects: Validates the player's direction choice, if the choice is valid then the snake begins moving in the
     *          given direction.
     */
    void changeDirection(Direction dir);

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the head (Rect at body[0]) of the snake.
     */
    Rect getHead() const;

    /*
     * Requires: Nothing
     * Modifies: body
     * Effects: Adds a new body segment(Rect) to the end of the snake's body.
     */
    void grow();

    /*
     * Requires: The width and height of the game window
     * Modifies: Nothing
     * Effects: Checks the two lose conditions of the game. The first being if the snake's head is overlapping with any
     *          part of it's body. The second is if the head of the snake is out of the bounds of the window.
     */
    bool checkLose(int width, int height);

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Draws each body segment(Rect) of the snake.
     */
    void draw() const;
};


#endif //M4OEP_GRAPHICS2_SNAKE_H
