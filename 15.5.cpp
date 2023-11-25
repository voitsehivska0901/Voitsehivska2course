#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>

class Circle {
private:
    double x;
    double y;
    double radius;

public:
    Circle(double centerX, double centerY, double circleRadius)
        : x(centerX), y(centerY), radius(circleRadius) {}


    ~Circle() {
        std::cout << "Circle (("<<x<<", "<<y<<"), "<<radius << ") destroyed.\n";
    }

    double getDiameter() const {
        return 2 * radius;
    }

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }

    std::vector<std::pair<double, double>> intersect(const Circle& otherCircle) const {
        double distance = std::sqrt((x - otherCircle.x) * (x - otherCircle.x) +
            (y - otherCircle.y) * (y - otherCircle.y));
        if ((distance == 0 && radius == otherCircle.radius) || distance <= std::abs(radius - otherCircle.radius) || distance >= radius + otherCircle.radius) {
            return {};
        }
            double a = (radius * radius - otherCircle.radius * otherCircle.radius + distance * distance) / (2 * distance);
            double h = std::sqrt(radius * radius - a * a);
            double x1 = x + a * (otherCircle.x - x) / distance;
            double y1 = y + a * (otherCircle.y - y) / distance;
            double x2 = x1 + h * (otherCircle.y - y) / distance;
            double y2 = y1 - h * (otherCircle.x - x) / distance;
            double x3 = x1 - h * (otherCircle.y - y) / distance;
            double y3 = y1 + h * (otherCircle.y - y) / distance;
            if (fabs(x2 - x3) < 1e-9 and fabs(y2 - y3) < 1e-9) {
                return { {x2, y2} };
            }
            return { {x2, y2}, {x3, y3} };
    }

    void updatePosition(double newX, double newY) {
        x = newX;
        y = newY;
    }
    std::pair<double, double> getCenter() const {
        return { x, y };
    }
};


std::vector<double> calculateMassCenter(const std::vector<Circle>& circles) {
    double vec_size = circles.size();

    double sumX = 0.0;
    double sumY = 0.0;

    // Calculate the sum of X and Y coordinates
    for (const Circle& circle : circles) {
        sumX += circle.getX();
        sumY += circle.getY();
    }

    // Calculate the mass center coordinates
    double massCenterX = sumX / vec_size;
    double massCenterY = sumY / vec_size;

    return { massCenterX, massCenterY };
}


int main() {
    std::vector<Circle> circles;
    circles.emplace_back(0, 0, 3);
    circles.emplace_back(4, 0, 2);

    for (size_t i = 0; i < circles.size(); i++) {
        const Circle& currentCircle = circles[i];
        std::cout << "Circle " << i + 1 << ":\n";
        std::cout << "Center: (" << currentCircle.getCenter().first << ", " << currentCircle.getCenter().second << ")\n";
        std::cout << "Diameter: " << currentCircle.getDiameter() << "\n";
        std::cout << "Area: " << currentCircle.getArea() << "\n";
        std::cout << "Circumference: " << currentCircle.getCircumference() << "\n\n";
    }

    std::vector<std::pair<double, double>> intersectionPoints = circles[0].intersect(circles[1]);
    if (!intersectionPoints.empty()) {
        std::cout << "Intersection Points:\n";
        for (const auto& point : intersectionPoints) {
            std::cout << "(" << point.first << ", " << point.second << ")\n";
        }
    }
    else {
        std::cout << "Circles do not intersect.\n";
    }
    std::vector<double> mass_centre = calculateMassCenter(circles);
    std::cout << "\nCenter of the mass:\n("<<mass_centre[0]<<", "<<mass_centre[1]<<")\n";
    std::cout << "\n";
    

    return 0;
}