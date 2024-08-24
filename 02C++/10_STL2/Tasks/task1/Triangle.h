#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Drawable.h"
#include <iostream>

class Triangle : public Drawable {
public:
    void draw() const override {
        std::cout << "Drawing a Triangle" << std::endl;
    }
};

#endif // TRIANGLE_H
