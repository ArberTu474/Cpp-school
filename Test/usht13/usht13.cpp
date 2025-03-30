#include <iostream>
#include <cmath>

// Base class Shape
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }
};

// Main function to test the classes
int main() {
    Shape* rectangle = new Rectangle(5.0, 10.0);
    Shape* circle = new Circle(7.0);

    std::cout << "Area of Rectangle: " << rectangle->area() << std::endl;
    std::cout << "Area of Circle: " << circle->area() << std::endl;

    // Clean up
    delete rectangle;
    delete circle;

    return 0;
}