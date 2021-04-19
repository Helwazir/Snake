#include "snake.h"

Snake::Snake() {
    Rect bodySegment = Rect(point2D(10, 10), dim);
    bodySegment.setColor(color(0, 0, 0));
    body.push_back(bodySegment);
}

void Snake::moveAndUpdateBody() {
    // Keep track of previous and next center position of each body segment
    point2D newCenter = body[0].getCenter();
    point2D prevCenter = body[0].getCenter();

    // Move each body segment i to the previous position of body segment i - 1
    for (int i = 1; i < body.size(); ++i) {
        prevCenter = body[i].getCenter();
        body[i].setCenter(newCenter);
        newCenter = prevCenter;
    }

    // Change the position of the head of the snake
    switch (currDirection){
        case LEFT:
            body[0].moveX(-20);
            break;
        case RIGHT:
            body[0].moveX(20);
            break;
        case UP:
            body[0].moveY(-20);
            break;
        case DOWN:
            body[0].moveY(20);
            break;
    }
}

void Snake::changeDirection(Direction dir) {
    switch (dir) {
        case LEFT:
            (currDirection != RIGHT) ? currDirection = LEFT : currDirection = RIGHT;
            break;
        case RIGHT:
            (currDirection != LEFT) ? currDirection = RIGHT : currDirection = LEFT;
            break;
        case UP:
            (currDirection != DOWN) ? currDirection = UP : currDirection = DOWN;
            break;
        case DOWN:
            (currDirection != UP) ? currDirection = DOWN : currDirection = UP;
            break;
    }
}

Rect Snake::getHead() const {
    return body[0];
}

void Snake::grow() {
    Rect bodySegment = Rect(body.back().getCenter(), dim);
    bodySegment.setColor(color(0, 0.0, 0));
    body.push_back(bodySegment);
}

bool Snake::checkLose(int width, int height) {
    // Losing this way is only possible when the length of the snake is > 4, otherwise the snake cannot touch itself
    if (body.size() > 4) {
        for (int i = 1; i < body.size(); ++i) {
            if (body[0].isOverlapping(body[i])) {
                return true;
            }
        }
    }
    // Check if the snake is out of bounds
    if (body[0].getLeftX() < 0 || body[0].getLeftX() > width || body[0].getTopY() < 0 || body[0].getBottomY() > height) {
        return true;
    }
    return false;
}

void Snake::draw() const {
    for (Rect r : body) {
        r.draw();
    }
}
