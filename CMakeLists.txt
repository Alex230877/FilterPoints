cmake_minimum_required(VERSION 3.10)
project(FilterPoints)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 11)

# Указываем все исходные файлы
add_executable(FilterPoints
    src/main.cpp
    src/Point.cpp
    src/Plane.cpp
    src/PointCloud.cpp
)

# Указываем директорию с заголовочными файлами
target_include_directories(FilterPoints PUBLIC ${PROJECT_SOURCE_DIR}/src)

