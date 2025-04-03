задание 6(12) e^x на отрезке x ∈ [-2;2]
import math
import matplotlib.pyplot as plt
import numpy as np

def calculate_exp_values(start, end, num_points=100):#оздает отрезок

  x_values = np.linspace(start, end, num_points)
  y_values = [math.exp(x) for x in x_values]  # Вычисляем e^x для каждого x

  return x_values, y_values


def plot_function(x_values, y_values):#создает график


  plt.plot(x_values, y_values)
  plt.xlabel("x")
  plt.ylabel("e^x")
  plt.title("График функции y = e^x на отрезке [-2; 2]")
  plt.grid(True) #сетка на графике
  plt.show()


if __name__ == "__main__":
  start_x = -2
  end_x = 2

  x_values, y_values = calculate_exp_values(start_x, end_x)
  plot_function(x_values, y_values)

  print("Пример значений:")
  for i in range(0, len(x_values), len(x_values) // 5):
      print(f"x = {x_values[i]:.2f}, e^x = {y_values[i]:.2f}")





задание 7(изменение цвета линии, тип линий, сохранить график в фаил пнг)еленый график и линия из точек и сохроняет _XxX_serega_XxX_.png
import math
import matplotlib.pyplot as plt
import numpy as np

def calculate_exp_values(start, end, num_points=100):#создает отрезок

  x_values = np.linspace(start, end, num_points)
  y_values = [math.exp(x) for x in x_values]

  return x_values, y_values


def plot_function(x_values, y_values, color='red', linestyle='--', filename='exp_graph.png'):


  plt.plot(x_values, y_values, color=color, linestyle=linestyle) #цвета и тип линии
  plt.xlabel("x")
  plt.ylabel("e^x")
  plt.title("График функции y = e^x на отрезке [-2; 2]")
  plt.grid(True) #сетка на графике
  plt.savefig(filename) # Сохранение графика в файл
  plt.show()


if __name__ == "__main__":
  start_x = -2
  end_x = 2

  x_values, y_values = calculate_exp_values(start_x, end_x)
  plot_function(x_values, y_values, color='green', linestyle=':', filename='_XxX_serega_XxX_.png')

  print("Пример значений:")
  for i in range(0, len(x_values), len(x_values) // 5):
      print(f"x = {x_values[i]:.2f}, e^x = {y_values[i]:.2f}")




задание 8(много линий разного цвета график)
1)(степенные многочлены с целыми степенями от 1 до 6 на отрезке [-1; 1];)
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 100)  # 100 точек на отрезке -1, 1
powers = range(1, 7)  # Степени от 1 до 6
colors = ['red', 'green', 'blue', 'purple', 'orange', 'brown']  # Цвета для графиков

plt.figure(figsize=(8, 6))  # Устанавливаем размер графика (8, 6)

for i, power in enumerate(powers):
    y = x ** power 
    plt.plot(x, y, color=colors[i], label=f'$x^{power}$')


plt.xlabel('x')  # Подпись X
plt.ylabel('y')  # Подпись  Y
plt.title('Степенные многочлены на отрезке [-1; 1]')
plt.grid(True)
plt.legend(loc='best')
plt.ylim(-1.2, 1.2) 

plt.show()


2)(синусоиды y = sin(ωt) с частотами ω= 2π, ω = 3π, ..., ω = 8π на отрезке t ∈ [-1;1])
import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(-1, 1, 100)  # 100 точек на отрезке -1, 1
frequencies = range(2, 9)  # ω = 2π, 3π, ..., 8π (частоты от 2 до 8)
colors = ['red', 'green', 'blue', 'purple', 'orange', 'brown', 'pink']  # Цвета для графиков

plt.figure(figsize=(8, 6))

for i, freq in enumerate(frequencies):
    omega = freq * np.pi  # Угловая частота ω = freq * π
    y = np.sin(omega * t)  # y = sin(ωt)
    plt.plot(t, y, color=colors[i], label=f'$sin({freq}\pi t)$')

plt.xlabel('t')
plt.ylabel('y')
plt.title('Синусоиды с разными частотами на отрезке [-1; 1]')
plt.grid(True)
plt.legend(loc='best')
plt.ylim(-1.2, 1.2)  # Ограничиваем Y

plt.show()


3)(синусоиды y=sin( 2pi*t + phi0) начальными фазами phi * 0 = 0 , \% 0 = π/6, , phi * 0 = 5pi / 6 на отрезке t \in [- 1; 1])
import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(-1, 1, 100)  # 100 точек на отрезке -1, 1
phi0_values = [0, np.pi / 6, 5 * np.pi / 6]  #в радианах
colors = ['red', 'green', 'blue']

plt.figure(figsize=(8, 6))

for i, phi0 in enumerate(phi0_values):
    y = np.sin(2 * np.pi * t + phi0)  # y = sin(2πt + φ0)
    plt.plot(t, y, color=colors[i], label=f'$sin(2\pi t + {phi0:.2f})$')


plt.xlabel('t')
plt.ylabel('y')
plt.title('Синусоиды с разными начальными фазами на отрезке [-1; 1]')
plt.grid(True)
plt.legend(loc='best')
plt.ylim(-1.2, 1.2)  # Ограничиваем Y

plt.show()


4)(логарифмические функции log(2) * (x) ln(x) и log_10(x) на отрезке x \in [1; 10])
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(1, 10, 100)  # 100 точек на отрезке 1, 10

y_log2 = np.log2(x)  # log2(x)
y_ln = np.log(x)     # ln(x) - натуральный логарифм
y_log10 = np.log10(x)  # log10(x)

colors = ['red', 'green', 'blue']

plt.figure(figsize=(8, 6))

plt.plot(x, y_log2, color=colors[0], label='$log_2(x)$')  # log2(x)
plt.plot(x, y_ln, color=colors[1], label='$ln(x)$')  # ln(x)
plt.plot(x, y_log10, color=colors[2], label='$log_{10}(x)$')  # log10(x)


plt.xlabel('x')
plt.ylabel('y')
plt.title('Логарифмические функции')
plt.grid(True)
plt.legend(loc='best')
#plt.ylim(0, 3)  # ограничить Y 

plt.show()

5)(гиперболические функции sh(x) ch(x) и th(x) на отрезке х Є [-10; 10], для их вычисления воспользуйтесь их выражением через экспоненту.)
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 100)  # 100 точек на отрезке -10, 10

# выраженные через экспоненту
sinh_x = (np.exp(x) - np.exp(-x)) / 2  # sh(x) = (e^x - e^-x) / 2
cosh_x = (np.exp(x) + np.exp(-x)) / 2  # ch(x) = (e^x + e^-x) / 2
tanh_x = sinh_x / cosh_x  # th(x) = sh(x) / ch(x)

colors = ['red', 'green', 'blue']

plt.figure(figsize=(8, 6))

plt.plot(x, sinh_x, color=colors[0], label='sh(x)')  # Гиперхуила синус
plt.plot(x, cosh_x, color=colors[1], label='ch(x)')  # Гиперхуила косинус
plt.plot(x, tanh_x, color=colors[2], label='th(x)')  # гиперболический тангенс

plt.xlabel('x')
plt.ylabel('y')
plt.title('Гиперболические функции')
plt.grid(True)
plt.legend(loc='best')
plt.ylim(-5, 5)  # Ограничение Y 

plt.show()

задание9
1)(в одни столбец;)
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 100)  # 100 точек на отрезке -1, 1
powers = range(1, 7) 
colors = ['red', 'green', 'blue', 'purple', 'orange', 'brown']

fig, axes = plt.subplots(len(powers), 1, figsize=(6, 12))  # 6 строк 1 столбец

for i, power in enumerate(powers):
    y = x ** power
    axes[i].plot(x, y, color=colors[i])
    axes[i].set_title(f'$x^{power}$')
    axes[i].set_xlabel('x')  # Подпись X
    axes[i].set_ylabel('y')  # Подпись Y
    axes[i].grid(True)
    axes[i].set_ylim(-1.1, 1.1)  # Ограничиваем Y


fig.suptitle('Степенные многочлены на отрезке [-1; 1]')

#расположение подграфиков (стобы друг на друга не залазили черти)
plt.tight_layout(rect=[0, 0.03, 1, 0.95])

plt.show()

2)(в два столбца)
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 100)  # 100 точек на отрезке -1, 1
powers = range(1, 7) 
colors = ['red', 'green', 'blue', 'purple', 'orange', 'brown']

fig, axes = plt.subplots(3, 2, figsize=(12, 12))  # 3 строки, 2 столбца

for i, power in enumerate(powers):
    row = i // 2 
    col = i % 2 
    y = x ** power
    axes[row, col].plot(x, y, color=colors[i])
    axes[row, col].set_title(f'$x^{power}$')
    axes[row, col].set_xlabel('x')  # Подпись X
    axes[row, col].set_ylabel('y')  # Подпись Y
    axes[row, col].grid(True)
    axes[row, col].set_ylim(-1.2, 1.2) # Ограничиваем Y

fig.suptitle('Степенные многочлены на отрезке [-1; 1]', fontsize=16)

plt.tight_layout(rect=[0, 0.03, 1, 0.95])

plt.show()

3)(в 3 столбца)
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 100)  # 100 точек на отрезке -1, 1
powers = range(1, 7)
colors = ['red', 'green', 'blue', 'purple', 'orange', 'brown']  # Цвета для графиков

fig, axes = plt.subplots(2, 3, figsize=(12, 8))  # 2 строки, 3 столбца
axes = axes.flatten()

for i, power in enumerate(powers):
    y = x ** power
    axes[i].plot(x, y, color=colors[i])
    axes[i].set_xlabel('x')  # Подпись X
    axes[i].set_ylabel('y')  # Подпись Y
    axes[i].set_title(f'$x^{power}$')
    axes[i].grid(True)
    axes[i].set_ylim(-1.2, 1.2)  # Ограничиваем Y

fig.suptitle('Степенные многочлены на отрезке [-1; 1]', fontsize=16)

#расположение подграфиков (стобы друг на друга не залазили черти)
plt.tight_layout(rect=[0, 0.03, 1, 0.95])

plt.show()

4)( в одну строку.)
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1, 1, 100)  # 100 точек на отрезке (-1, 1)
powers = range(1, 7)
colors = ['red', 'green', 'blue', 'purple', 'orange', 'brown']

fig, axes = plt.subplots(1, 6, figsize=(18, 4))  # 1 строка, 6 столбцов

for i, power in enumerate(powers):
    y = x ** power  # Вычисляем y = x^power
    axes[i].plot(x, y, color=colors[i])
    axes[i].set_xlabel('x')  # Подпись X
    axes[i].set_ylabel('y')  # Подпись Y
    axes[i].set_title(f'$x^{power}$') 
    axes[i].grid(True)
    axes[i].set_ylim(-1.2, 1.2)  # Ограничиваем  Y

fig.suptitle('Степенные многочлены на отрезке [-1; 1]', fontsize=16)

#расположение подграфиков (стобы друг на друга не залазили черти)
plt.tight_layout(rect=[0, 0.03, 1, 0.95])


plt.show()








задание10(построить круговую диограму которая показывают общую часть студентов вашей групы)
import matplotlib.pyplot as plt


total_students = 30  #количество студентов

excellent_students = 3  #одни пятёрки
good_excellent_students = 8  # пятёрки и четвёрки
satisfactory_students = 10  # троишники без долгов
debt_passed_students = 5  # должиники бандито
expelled_students = 4  # двоишники глупые (отчислены!!!)

if sum([excellent_students, good_excellent_students, satisfactory_students, debt_passed_students, expelled_students]) != total_students:
    print("Ошибка: Сумма студентов по категориям не равна общему числу студентов.")
    exit()

excellent_share = excellent_students / total_students
good_excellent_share = good_excellent_students / total_students
satisfactory_share = satisfactory_students / total_students
debt_passed_share = debt_passed_students / total_students
expelled_share = expelled_students / total_students


labels = ['Отличники', 'Пятёрки и Четвёрки', 'троишники без долгов', 'должиники бандитов', 'двоишники глупые (отчислены!!!)']
sizes = [excellent_share, good_excellent_share, satisfactory_share, debt_passed_share, expelled_share]
colors = ['gold', 'lightgreen', 'lightcoral', 'skyblue', 'red']
explode = (0.1, 0, 0, 0, 0)

plt.figure(figsize=(10, 10))  # диаграмму круглой
plt.pie(sizes, explode=explode, labels=labels, colors=colors,
        autopct='%1.1f%%', shadow=True, startangle=140)

plt.axis('equal')
plt.title('Успеваемость студентов группы ксп 227')
plt.show()





задание11(z= xy)
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def z_function(x, y):
  return x * y

x = np.linspace(-3, 3, 100)  # 100 точек от -3 до 3 по оси x
y = np.linspace(-3, 3, 100)  # 100 точек от -3 до 3 по оси y

X, Y = np.meshgrid(x, y)  #координатную сетка
Z = z_function(X, Y)       # значения функции z на сетке


plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
contour = plt.contourf(X, Y, Z, cmap='viridis')
plt.colorbar(contour)                            
plt.xlabel('x')
plt.ylabel('y')
plt.title('Закрашенная Контурная Диаграмма z = xy')

plt.subplot(1, 2, 2)

fig = plt.figure(figsize=(12, 6))
ax = fig.add_subplot(111, projection='3d')  #3D подграфик
surface = ax.plot_surface(X, Y, Z, cmap='viridis')
fig.colorbar(surface) #цветовую шкалу

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Трехмерный график z = xy')

plt.tight_layout()
plt.show()