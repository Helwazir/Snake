//
// Created by haz on 4/19/21.
//

#ifndef M4OEP_GRAPHICS2_SNAKE_H
#define M4OEP_GRAPHICS2_SNAKE_H

#include <vector>
#include "rect.h"
using std::vector;


enum Direction {LEFT, RIGHT, UP, DOWN};

class Snake {
private:
    int length;
    dimensions dim = dimensions(20, 20);
    Direction currDirection;
    vector<Rect> body;

public:
    Snake();
    int getLength();

    void moveAndUpdateBody();
    void changeDirection(Direction dir);
    Rect getHead();
    void grow();
    bool checkLose(int width, int height);




    void draw() const;

};


#endif //M4OEP_GRAPHICS2_SNAKE_H
