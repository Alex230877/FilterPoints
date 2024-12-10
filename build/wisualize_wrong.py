import numpy as np
import matplotlib.pyplot as plt

# Функция для загрузки точек из файла
def load_points(filename):
    return np.loadtxt(filename)

# Загрузка ложных точек
wrong_points = load_points("points_wrong.txt")

# Разделение координат для точек
wrong_x, wrong_y, wrong_z = wrong_points[:, 0], wrong_points[:, 1], wrong_points[:, 2]

# Визуализация
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')

# Отображение только ложных точек
ax.scatter(wrong_x, wrong_y, wrong_z, c='red', label='Ложные точки', s=40, alpha=0.8)

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
