#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Drawable.h"
#include <iostream>

class Rectangle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

#endif // RECTANGLE_H
