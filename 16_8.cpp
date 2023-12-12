#include <iostream>
#include <vector>
#include <cmath>

class Shape {
public:
    //virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual bool isConvex() const = 0;
    virtual ~Shape() {}
};

class Point {
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
};

class Rectangle : public Shape {
private:
    Point upperLeft;
    Point lowerRight;

public:
    Rectangle(const Point& upperLeft, const Point& lowerRight)
        : upperLeft(upperLeft), lowerRight(lowerRight) {}

    double getLength() const {
        return std::abs(lowerRight.x - upperLeft.x);
    }

    double getWidth() const {
        return std::abs(lowerRight.y - upperLeft.y);
    }

    double getArea() const {
        return getLength() * getWidth();
    }

    double getPerimeter() const override {
        return 2 * (getLength() + getWidth());
    }

    bool isConvex() const override {
        return true;
    }
};

class Triangle : public Shape {
private:
    Point vertices[3];

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3): 
        vertices{ p1, p2, p3} {}

    double getSideLength(int i, int j) const {
        return std::sqrt(std::pow(vertices[i].x - vertices[j].x, 2) +
            std::pow(vertices[i].y - vertices[j].y, 2));
    }

    double getLength(const Point& p1, const Point& p2) const {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    double getArea() const {
        double a = getLength(vertices[0], vertices[1]);
        double b = getLength(vertices[1], vertices[2]);
        double c = getLength(vertices[2], vertices[0]);

        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));

        return area;
    }

    double getPerimeter() const override {
        return getSideLength(0, 1) + getSideLength(1, 2) + getSideLength(2, 0);
    }

    bool isConvex() const override {
        return true;
    }
};

class Pentagon : public Shape {
private:
    Point vertices[5];

public:
    Pentagon(const Point& p1, const Point& p2, const Point& p3,
        const Point& p4, const Point& p5)
        : vertices{ p1, p2, p3, p4, p5 } {}

    double getSideLength(int i, int j) const {
        return std::sqrt(std::pow(vertices[i].x - vertices[j].x, 2) +
            std::pow(vertices[i].y - vertices[j].y, 2));
    }

    double getPerimeter() const override {
        double length = 0;
        for (int i = 0; i < 4;i++)
            length += getSideLength(i, i + 1);
        return length+getSideLength(0,4);
    }

    bool isConvex() const override {
        int n = 5;
        bool isConvex = true;
        for (int i = 0; i < n; i++) {
            double x1 = vertices[(i + 1) % n].x - vertices[i].x;
            double y1 = vertices[(i + 1) % n].y - vertices[i].y;
            double x2 = vertices[(i + 2) % n].x - vertices[(i + 1) % n].x;
            double y2 = vertices[(i + 2) % n].y - vertices[(i + 1) % n].y;

            double crossProduct = x1 * y2 - x2 * y1;
            if (i == 0) {
                isConvex = crossProduct > 0;
            }
            else if ((crossProduct > 0 && !isConvex) || (crossProduct < 0 && isConvex)) {
                return false;
            }
        }

        return true;
    }
};

class Polygon : public Shape {
private:
    std::vector<Point> vertices;

public:
    Polygon(const std::vector<Point>& vertices) : vertices(vertices) {}

    double getSideLength(int i, int j) const {
        return std::sqrt(std::pow(vertices[i].x - vertices[j].x, 2) +
            std::pow(vertices[i].y - vertices[j].y, 2));
    }

    double getPerimeter() const override {
        double length = 0;
        for (int i = 0; i < vertices.size()-1;i++)
            length += getSideLength(i, i + 1);
        return length + getSideLength(0, vertices.size()-1);
    }

    bool isConvex() const override {
        int n = vertices.size();
        bool isConvex = true;
        for (int i = 0; i < n; i++) {
            double x1 = vertices[(i + 1) % n].x - vertices[i].x;
            double y1 = vertices[(i + 1) % n].y - vertices[i].y;
            double x2 = vertices[(i + 2) % n].x - vertices[(i + 1) % n].x;
            double y2 = vertices[(i + 2) % n].y - vertices[(i + 1) % n].y;

            double crossProduct = x1 * y2 - x2 * y1;
            if (i == 0) {
                isConvex = crossProduct > 0;
            }
            else if ((crossProduct > 0 && !isConvex) || (crossProduct < 0 && isConvex)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::vector<Shape*> shapes;
    Rectangle rectangle(Point(0, 0), Point(3, 4));
    Triangle triangle(Point(0, 0), Point(3, 0), Point(0, 4));
    Pentagon pentagon(Point(0, 0), Point(1, 1), Point(2, 0), Point(2, 2), Point(1, 3));

    std::vector<Shape*> convexPolygons;
    for (const auto& shape : shapes) {
        if (shape->isConvex()) {
            convexPolygons.push_back(shape);
        }
    }
    std::cout << "Got " << convexPolygons.size() << " convex shapes\n";

    if (!convexPolygons.empty()) {
        Shape* minPerimeterShape = convexPolygons[0];
        for (const auto& shape : convexPolygons) {
            if (shape->getPerimeter() < minPerimeterShape->getPerimeter()) {
                minPerimeterShape = shape;
            }
        }

        std::cout << "The convex polygon with the smallest perimeter has a perimeter of "
            << minPerimeterShape->getPerimeter() << std::endl;
    }

    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}