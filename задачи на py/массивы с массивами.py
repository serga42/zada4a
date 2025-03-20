#выведет количество и сумму эллементов всего массива 

import numpy as np

my_array = np.random.randint(0, 10, 100)

array_sum = 0
array_length = 0

for element in my_array:
    array_sum += element
    array_length += 1

print(f"Сумма: {array_sum}")
print(f"Количество: {array_length}")

#вычислит среднее арифметическое массива 

import numpy as np

my_array = np.random.randint(0, 10, 80)

array_sum = 0
array_length = 0

for element in my_array:
    array_sum += element
    array_length += 1
average = array_sum/array_length
print(f"Среднее арифметическое: {average}")

#переписывает все эллементы из одного массива в другой и считает их кол во

import numpy as np

my_array = np.random.randint(0, 10, 70)
my_arr2 = []

count = 0
array_length = 0

for element in my_array:
    my_arr2.append(element)
    count += 1
    array_length += 1
print(f'Массив: {my_arr2}')
print(f'Длинна: {array_length}')

#определяет максимальный эллемент массива и его порядковый номер

import random

arr=[random.randint(0,100) for i in range(50)]
print(arr)
print(max(arr))
print(arr.index(max(arr))+1)

#определяет минимальный эллемент массива и его порядковый номер

import random

arr=[random.randint(0,100) for i in range(40)]
print(arr)
print(min(arr))
print(arr.index(min(arr))+1)


#находит максимальный и минимальный эллемент массива и меняет их местами
import random

arr=[random.randint(0,100) for i in range(80)]
print(arr)
index_min = arr.index(min(arr))
index_max = arr.index(max(arr))
print('Минимальный: ', min(arr))
print('Максимальный: ', max(arr))

minsave = arr[index_min]
arr[index_min] = arr[index_max]
arr[index_max] = minsave
print(arr)

#вычисляет среднее геометрическое эллементов массива
import random
import math

arr=[random.randint(0,100) for i in range(20)]
umnojarr = 1
for element in arr:
    umnojarr *= element
    
otvet = math.pow(umnojarr, 1/len(arr))

print('Среднеее геометрическое: ', otvet)

#сортирует 1 массив и располагает эллементы во 2 массиве, так что бы сначала шли положительные потом отрицательные
import random
import math

arr=[random.randint(-100,100) for i in range(30)]
arr2 = []

positive_numbers = []
negative_numbers = []

for element in arr:
    if element >= 0:
        positive_numbers.append(element)
    else:
        negative_numbers.append(element)

arr2 = positive_numbers + negative_numbers
print('Массив: ', arr)
print('Сортированный массив: ', arr2)

#определяет сумму эллементов массива, которые кратные 3

import random

arr=[random.randint(0,100) for i in range(50)]
sum = 0
for element in arr:
    if element % 3 == 0:
        sum += element
        
print('Массив: ', arr)
print('Сумма эллементов, которые кратные 3: ', sum)

#вычисляет сумму и количество эллементов массива с вводом его размера
import random
number = int(input('Введите число эллементов массива: '))
arr=[random.randint(0,100) for i in range(number)]
array_sum = 0
array_length = 0

for element in arr:
    array_sum += element
    array_length += 1

print(f"Сумма: {array_sum}")
print(f"Количество: {array_length}")

#находит среднее геометрическое введеного эллеметов массива

import random
import math
number = int(input('Введите число эллементов массива: '))
arr=[random.randint(0,100) for i in range(number)]
umnojarr = 1
for element in arr:
    umnojarr *= element
    
otvet = math.pow(umnojarr, 1/len(arr))

print('Среднеее геометрическое: ', otvet)

#преписывает все положительные эллементы массива в другой, с вводом количества эллементов

import random

number = int(input('Введите число эллементов массива: '))
arr=[random.randint(-100,100) for i in range(number)]

arr2 = []

positive_numbers = []
negative_numbers = []

for element in arr:
    if element >= 0:
        positive_numbers.append(element)
    else:
        negative_numbers.append(element)
arr2 = positive_numbers

print('Массив', arr)
print('Массив с положительными числами: ', arr2)

#преписывает все положительные эллементы массива в другой массив,а отрицательные в другой с вводом количества эллементов

import random

number = int(input('Введите число эллементов массива: '))
arr=[random.randint(-100,100) for i in range(number)]

arr2 = []
arr3 = []

positive_numbers = []
negative_numbers = []

for element in arr:
    if element >= 0:
        positive_numbers.append(element)
    else:
        negative_numbers.append(element)
arr2 = positive_numbers
arr3 = negative_numbers
print('Массив', arr)
print('Массив с положительными числами: ', arr2)
print('Массив с отрицательными числами числами: ', arr3)

#определяет максимальный эллемент массива и его номер с вводом эллементов

import random

number = int(input('Введите число эллементов массива: '))
arr=[random.randint(0,100) for i in range(number)]

print('Массив: ', arr)
print('Максимальный эллемент: ', max(arr))
print('Его номер: ', arr.index(max(arr))+1)

#определяет минимальный эллемент массива и его номер с вводом эллементов

import random

number = int(input('Введите число эллементов массива: '))
arr=[random.randint(0,100) for i in range(number)]

print('Массив: ', arr)
print('Максимальный эллемент: ', min(arr))
print('Его номер: ', arr.index(min(arr))+1)