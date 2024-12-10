#include "PointCloud.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Чтение точек из файла
void PointCloud::read_from_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        double x, y, z;
        ss >> x >> y >> z;
        points.push_back(Point(x, y, z));
    }
    file.close();
}

// Разделение точек на "корректные" и "ложные"
void PointCloud::filter_points(const Plane& plane1, const Plane& plane2, vector<Point>& good_points, vector<Point>& wrong_points) {
    for (const auto& point : points) {
        if (plane1.is_inside(point) || plane2.is_inside(point)) {
            wrong_points.push_back(point); // Точка со стороны робота
        } else {
            good_points.push_back(point); // Корректная точка
        }
    }
}

