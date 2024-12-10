#ifndef POINT_H
#define POINT_H

class Point {
public:
    double x, y, z;

    // Конструктор по умолчанию
    Point(double x = 0, double y = 0, double z = 0);

    // Вычисление расстояния от этой точки до другой
    double distance_to(const Point& p) const;
};

#endif // POINT_H
