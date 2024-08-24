#include "Drawable.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    Drawable* drawableObjects[] = { &circle, &rectangle, &triangle };

    for (Drawable* drawable : drawableObjects) {
        drawable->draw();
    }

    return 0;
}
