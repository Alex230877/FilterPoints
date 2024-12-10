#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Point.h"
#include "Plane.h"
#include "PointCloud.h"

using namespace std;

// Функция для сохранения точек в файл
void save_points(const string& filename, const vector<Point>& points) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл для записи " << filename << endl;
        exit(1);
    }

    for (const auto& point : points) {
        file << point.x << " " << point.y << " " << point.z << endl;
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Использование: " << argv[0] << " <points_file> <planes_file>" << endl;
        return 1;
    }

    string points_file = argv[1];
    string planes_file = argv[2];

    // Загрузка точек
    PointCloud point_cloud;
    point_cloud.read_from_file(points_file);

    // Загрузка плоскостей
    PointCloud plane_points;
    plane_points.read_from_file(planes_file);

    if (plane_points.points.size() != 6) {
        cerr << "Ошибка: Файл planes.txt должен содержать ровно 6 точек." << endl;
        return 1;
    }

    // Создание плоскостей
    Plane plane1(plane_points.points[0], plane_points.points[1], plane_points.points[2]);
    Plane plane2(plane_points.points[3], plane_points.points[4], plane_points.points[5]);

    // Фильтрация точек
    vector<Point> good_points, wrong_points;
    point_cloud.filter_points(plane1, plane2, good_points, wrong_points);

    // Сохранение результатов в файлы с фиксированными именами
    string output_good = "points_good.txt";  // Фиксированное имя для хороших точек
    string output_wrong = "points_wrong.txt";  // Фиксированное имя для ложных точек
    save_points(output_good, good_points);
    save_points(output_wrong, wrong_points);

    cout << "Результаты сохранены:\n"
         << "Корректные точки: " << output_good << "\n"
         << "Ложные точки: " << output_wrong << endl;

    return 0;
}

