//
// Created by haz on 4/19/21.
//

#include <iostream>
#include "snake.h"


Snake::Snake() {
    length = 1;
    Rect bodySegment = Rect(point2D(10, 10), dimensions(20, 20));
    bodySegment.setColor(color(0, 0, 0));
    body.push_back(bodySegment);
}

int Snake::getLength() {
    return length;
}

void Snake::moveAndUpdateBody() {
    point2D newCenter = body[0].getCenter();
    point2D prevCenter = body[0].getCenter();

    for (int i = 1; i < body.size(); ++i) {
        prevCenter = body[i].getCenter();
        body[i].setCenter(newCenter);
        newCenter = prevCenter;

    }
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

Rect Snake::getHead() {
    return body[0];
}

void Snake::grow() {
    std::cout << "GROWING" << std::endl;

    Rect bodySegment = Rect(body.back().getCenter(), dimensions(20, 20));
    bodySegment.setColor(color(0, 0.25, 0));
    body.push_back(bodySegment);
    ++length;
    std::cout << "Length: " << length << std::endl;
}

bool Snake::checkLose(int width, int height) {
    if (body.size() > 4) {
        for (int i = 1; i < body.size(); ++i) {
            if (body[0].isOverlapping(body[i])) {
                return true;
            }
        }
    }
    if (body[0].getLeftX() < 0 || body[0].getLeftX() > width || body[0].getTopY() < 0 || body[0].getBottomY() > height) {
        return true;
    }
    return false;
}

void Snake::draw() const {
    for (Rect r : body) {
        r.draw();
    }

//    body[0].draw();
}
