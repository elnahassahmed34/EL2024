#ifndef DRAWABLE_H
#define DRAWABLE_H

class Drawable {
public:
    virtual ~Drawable() = default; // Virtual destructor
    virtual void draw() const = 0; // Pure virtual function
};

#endif // DRAWABLE_H
