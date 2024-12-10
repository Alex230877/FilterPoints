import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def load_points(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            points.append(tuple(map(float, line.split())))
    return points

# Загрузка точек из входного файла
points = load_points("points.txt")

# Разделяем координаты
x, y, z = zip(*points)

# Визуализация массива входных точек
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x, y, z, c='b', label='Входные точки')
ax.legend()
ax.set_title('Массив входных точек')
plt.show()