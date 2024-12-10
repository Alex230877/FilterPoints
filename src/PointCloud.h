#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "Point.h"
#include "Plane.h"
#include <vector>
#include <string>

class PointCloud {
public:
    std::vector<Point> points;

    // Чтение точек из файла
    void read_from_file(const std::string& filename);

    // Разделение точек на корректные и ложные
    void filter_points(const Plane& plane1, const Plane& plane2, std::vector<Point>& good_points, std::vector<Point>& wrong_points);
};

#endif // POINTCLOUD_H

