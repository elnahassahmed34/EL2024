#ifndef CIRCLE_H
#define CIRCLE_H

#include "Drawable.h"
#include <iostream>

class Circle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

#endif // CIRCLE_H
