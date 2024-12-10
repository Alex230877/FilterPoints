#include "Point.h"
#include <cmath>

// Конструктор
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

// Вычисление расстояния до другой точки
double Point::distance_to(const Point& p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
}