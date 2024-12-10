#include "Plane.h"

// Конструктор, вычисляет нормаль плоскости и коэффициент D
Plane::Plane(const Point& p1, const Point& p2, const Point& p3) {
    double nx = (p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y);
    double ny = (p2.z - p1.z) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.z - p1.z);
    double nz = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

    A = nx;
    B = ny;
    C = nz;

    // Вычисление D
    D = -(A * p1.x + B * p1.y + C * p1.z);
}

// Проверка, находится ли точка со стороны робота
bool Plane::is_inside(const Point& point) const {
    double d = A * point.x + B * point.y + C * point.z + D;
    return d < 0; // Точка считается "ложной", если она со стороны робота
}