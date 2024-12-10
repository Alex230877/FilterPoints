#ifndef PLANE_H
#define PLANE_H

#include "Point.h"

class Plane {
public:
    double A, B, C, D;

    // Конструктор, принимает три точки, определяющие плоскость
    Plane(const Point& p1, const Point& p2, const Point& p3);

    // Проверка, находится ли точка со стороны робота
    bool is_inside(const Point& point) const;
};

#endif // PLANE_H
