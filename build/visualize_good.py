import numpy as np
import matplotlib.pyplot as plt

# Функция для загрузки точек из файла
def load_points(filename):
    return np.loadtxt(filename)

# Загрузка корректных точек
good_points = load_points("points_good.txt")

# Разделение координат для точек
good_x, good_y, good_z = good_points[:, 0], good_points[:, 1], good_points[:, 2]

# Визуализация
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')

# Отображение только корректных точек
ax.scatter(good_x, good_y, good_z, c='blue', label='Корректные точки', s=40, alpha=0.8)

# Настройка осей
ax.set_xlabel("X", fontsize=12)
ax.set_ylabel("Y", fontsize=12)
ax.set_zlabel("Z", fontsize=12)

# Легенда
ax.legend(fontsize=10)

# Углы обзора
ax.view_init(elev=30, azim=45)

# Показ графика
plt.show()
