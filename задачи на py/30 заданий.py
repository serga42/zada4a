Вариант 1
#############вычислить сумму и число положительных эллементов матрицы A[N, N] находящихсяя над диагональю

def sum_and_count_above_diagonal(matrix):
    N = len(matrix)
    sum_positive = 0
    count = 0

    for i in range(N):
        for j in range(i + 1, N):
            if matrix[i][j] > 0:
                sum_positive += matrix[i][j]
                count += 1

    return sum_positive, count

A = [
    [1, -2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

sum_pos, cnt = sum_and_count_above_diagonal(A)
print(f"Сумма положительных элементов над диагональю: {sum_pos}")
print(f"Количество таких элементов: {cnt}")

##########Дана матрица B [N, M] найти в каждой строке матрицы максимальный и минимальный эллемент и 
поменять с первым и последним элементами строки

def swap_max_min_in_rows(matrix):
    for row in matrix:
        if len(row) == 0:
            continue 

        max_val = max(row)
        min_val = min(row)
        j_max = row.index(max_val)
        j_min = row.index(min_val)

        row[0], row[j_max] = row[j_max], row[0]

        row[-1], row[j_min] = row[j_min], row[-1]

B = [
    [3, 7, 2, 8],
    [5, 1, 9, 4],
    [6, 0, 3, 2]
]

print("Исходная матрица:")
for row in B:
    print(row)

swap_max_min_in_rows(B)

print("\nМатрица после замен:")
for row in B:
    print(row)

Вариант 2
###########дана целая квадратная матрица N-го порядка, определить является ли она магическим квадратом
т.е. такой матрицей в которой суммы эллементов во всех строках и столбцах одинаковы

def is_magic_square(matrix):
    N = len(matrix)
    if N == 0 or len(matrix[0]) != N:
        return False

    magic_const = N * (N**2 + 1) // 2

    for row in matrix:
        if sum(row) != magic_const:
            return False

    for j in range(N):
        col_sum = sum(matrix[i][j] for i in range(N))
        if col_sum != magic_const:
            return False

    diag1_sum = sum(matrix[i][i] for i in range(N))
    if diag1_sum != magic_const:
        return False

    diag2_sum = sum(matrix[i][N - 1 - i] for i in range(N))
    if diag2_sum != magic_const:
        return False

    elements = [num for row in matrix for num in row]
    if sorted(elements) != list(range(1, N**2 + 1)):
        return False

    return True

matrix = [
    [8, 1, 6],
    [3, 5, 7],
    [4, 9, 2]
]

print(is_magic_square(matrix))

##############Дана прямоугольная матрица A[N, N], переставить первый и последний столбцы местами и вывести на экран

def swap_first_last_columns(matrix):
    for row in matrix:
        row[0], row[-1] = row[-1], row[0]
    return matrix

A = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]

swapped_matrix = swap_first_last_columns(A)

for row in swapped_matrix:
    print(row)

Вариант 3
#############определить является ли заданная целая квадратная матрица N-го порядка симметричной(относительно главной диагонали)

def is_symmetric(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(i + 1, n):
            if matrix[i][j] != matrix[j][i]:
                return False
    return True
 
matrix = [
    [1, 2, 3],
    [2, 4, 5],
    [3, 5, 6]
]
print(is_symmetric(matrix))


##########дана вещественная матрица размером N X M. 
переставляя ее строки и столбцы добиться того, что бы наибольший эллемент или 1 из них оказался в верхнем левом углу

import numpy as np

def move_max_to_top_left(matrix):
    matrix = np.array(matrix)
    n, m = matrix.shape

    max_val = matrix.max()
    max_indices = np.argwhere(matrix == max_val)
    i_max, j_max = max_indices[0] 

    matrix[[0, i_max]] = matrix[[i_max, 0]]

    matrix[:, [0, j_max]] = matrix[:, [j_max, 0]]

    return matrix


matrix = [
    [1, 2, 3],
    [4, 9, 5],
    [6, 7, 8]
]

result = move_max_to_top_left(matrix)
print(result)

Вариант 4
##########Дана прямоугольная матрица.Найти строку с наибольшей и строку и наименьшей суммой элементов.

def find_min_max_sum_rows(matrix):
    if not matrix:
        return None, None

    sum_rows = [sum(row) for row in matrix]

    min_sum_index = sum_rows.index(min(sum_rows))
    max_sum_index = sum_rows.index(max(sum_rows))

    return matrix[min_sum_index], matrix[max_sum_index]

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [0, 0, 0]
]

min_row, max_row = find_min_max_sum_rows(matrix)

print("Строка с наименьшей суммой:", min_row)
print("Сумма наименьших:", sum(min_row))
print("Строка с наибольшей суммой:", max_row)
print("Сумма наибольших:", sum(max_row))

#############дана квадратнаяя матрица A[N, N] записать на место отрицательных элементов матрицы нули а на место положительных 1

def replace_matrix_elements(matrix):
    n = len(matrix)
    for i in range(n):
        for j in range(n):
            if matrix[i][j] > 0:
                matrix[i][j] = 1
            elif matrix[i][j] < 0:
                matrix[i][j] = 0
    return matrix

A = [
    [3, -2, 0],
    [5, -1, 2],
    [-4, 6, -3]
]

print("Исходная матрица:")
for row in A:
    print(row)

A = replace_matrix_elements(A)

print("\nПреобразованная матрица:")
for row in A:
    print(row)

Вариант 5

#########Упорядочить по возрастанию элементы каждой строки матрицы размером n x m

def sort_matrix_rows(matrix):
    for row in matrix:
        row.sort()
    return matrix

matrix = [
    [3, 1, 4],
    [9, 5, 2],
    [6, 8, 7]
]

print("Исходная матрица:")
for row in matrix:
    print(row)

sorted_matrix = sort_matrix_rows(matrix)

print("\nМатрица после сортировки строк:")
for row in sorted_matrix:
    print(row)

##########дана действительная матрица размером n x m, все элементы которой различны в каждой строке выбирается элемент с наименьшим значнием
если число четное, то заменяется 0, если нет 1

def replace_min_elements(matrix):
    for row in matrix:
        min_val = min(row) 
        min_index = row.index(min_val)
        row[min_index] = 0 if min_val % 2 == 0 else 1
    return matrix

matrix = [
    [4, 3, 5],
    [2, 7, 6],
    [9, 8, 1]
]

print("Исходная матрица:")
for row in matrix:
    print(row)

new_matrix = replace_min_elements(matrix)

print("\nМатрица после замены:")
for row in new_matrix:
    print(row)

Вариант 6
########дана целочисленая квадратная матрица найти в каждой строке наибольший элемент и в каждом столбце наименьший

def find_max_in_rows_and_min_in_columns(matrix):
    n = len(matrix)

    max_in_rows = [max(row) for row in matrix]

    min_in_columns = [min(matrix[i][j] for i in range(n)) for j in range(n)]

    return max_in_rows, min_in_columns


########### Пример использования
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

max_in_rows, min_in_columns = find_max_in_rows_and_min_in_columns(matrix)

print("Максимальные элементы в строках:", max_in_rows)
print("Минимальные элементы в столбцах:", min_in_columns)

##########дана действительная квадратная матрица порядка N(N-нечетное), все элементы которого различны, найти наибольшимй элемент
среди стоящий на главной побочной диагоналях и поменять местами с элементом стоящим на пересечении этих диагоналей

def swap_max_with_center(matrix):
    N = len(matrix)
    center_pos = (N - 1) // 2

    diagonal_elements = []
    for i in range(N):
        diagonal_elements.append(matrix[i][i])
        if i != N - 1 - i:
            diagonal_elements.append(matrix[i][N - 1 - i])

    max_val = max(diagonal_elements)

    max_pos = None
    for i in range(N):
        if matrix[i][i] == max_val:
            max_pos = (i, i)
            break
        if matrix[i][N - 1 - i] == max_val:
            max_pos = (i, N - 1 - i)
            break

    if max_pos:
        matrix[center_pos][center_pos], matrix[max_pos[0]][max_pos[1]] = \
            matrix[max_pos[0]][max_pos[1]], matrix[center_pos][center_pos]

    return matrix


N = 5
matrix = [
    [1, 2, 3, 4, 5],
    [6, 7, 8, 9, 10],
    [11, 12, 13, 14, 15],
    [16, 17, 18, 19, 20],
    [21, 22, 23, 24, 25]
]

print("Исходная матрица:")
for row in matrix:
    print(row)

matrix = swap_max_with_center(matrix)

print("\nМатрица после замены:")
for row in matrix:
    print(row)

Вариант 7 
#########квадратная матрица симетричная относительно главной диагонали задана верхним треугольником в виде одномерного массива
востановить исходную матрицу и напечатать строками

def restore_symmetric_matrix(upper_triangle):
    n = int((2 * len(upper_triangle)) ** 0.5)
    if n * (n + 1) // 2 != len(upper_triangle):
        raise ValueError("Некорректная длина входного массива")

    matrix = [[0] * n for _ in range(n)]

    index = 0
    for i in range(n):
        for j in range(i, n):
            matrix[i][j] = upper_triangle[index]
            index += 1

    for i in range(n):
        for j in range(i):
            matrix[i][j] = matrix[j][i]

    return matrix


upper_triangle = [1, 2, 3, 4, 5, 6]  
matrix = restore_symmetric_matrix(upper_triangle)

for row in matrix:
    print(row)

########для заданной квадратной матрицы сформировать одномерный массив из ее диагональных элементов, найти след матрицы
просуммировав элементы одномерного масива, преобразовать исходную матрицу по правилам: четные строки разделить на полученное значение 
нечетные оставить без изменения

import numpy as np

matrix = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])

diagonal_elements = np.diag(matrix)
print("Диагональные элементы:", diagonal_elements)

trace = np.sum(diagonal_elements)
print("След матрицы:", trace)

Вариант 8
##########задана матрица порядка n и число k разделить элементы k-е степени на диагональной элемент расположеный в этой строке 

import numpy as np


def transform_matrix(matrix, k):
    n = len(matrix)
    transformed = matrix.astype(float).copy()

    for i in range(n):
        diag_element = matrix[i][i]

        for j in range(n):
            transformed[i][j] = (matrix[i][j] ** k) / diag_element

    return transformed


matrix = np.array([
    [2, 3, 1],
    [4, 5, 2],
    [3, 2, 4]
])
k = 2

print("Исходная матрица:")
print(matrix)

result = transform_matrix(matrix, k)

print("\nПреобразованная матрица:")
print(result)

########задана квадратная матрица получить транспонированную матрицу

def transpose_matrix(matrix):
    n = len(matrix)
    transposed = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            transposed[j][i] = matrix[i][j]

    return transposed


matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print("Исходная матрица:")
for row in matrix:
    print(row)

result = transpose_matrix(matrix)

print("\nТранспонированная матрица:")
for row in result:
    print(row)

Вариант 9
########для целочисленной квадратной матрицы найти число элементов кратных k и наибольший элемент

def analyze_matrix(matrix, k):
    count = 0
    max_element = matrix[0][0]

    for row in matrix:
        for element in row:
            if element % k == 0:
                count += 1
            if element > max_element:
                max_element = element

    return count, max_element


matrix = [
    [15, 20, 25],
    [10, 18, 22],
    [12, 24, 30]
]
k = 5

multiples_count, maximum = analyze_matrix(matrix, k)

print(f"Число элементов, кратных {k}: {multiples_count}")
print(f"Наибольший элемент матрицы: {maximum}")

######в данной действительной квадратной матрице порядка N найти наибольший по модулю число, получить квадратную матрицу порядка n-1
путем отбрасывания из исходной матрицы строки и столбца на пересечении которых расположен элемент с найденым значением

import numpy as np


def process_matrix(matrix):
    matrix = np.array(matrix, dtype=float)
    n = len(matrix)

    abs_matrix = np.abs(matrix)
    max_val = np.max(abs_matrix)

    positions = np.argwhere(abs_matrix == max_val)

    i, j = positions[0]

    new_matrix = np.delete(matrix, i, axis=0)  
    new_matrix = np.delete(new_matrix, j, axis=1)  

    return new_matrix


matrix = [
    [1.2, -3.5, 0.8],
    [4.1, 2.7, -5.9],
    [0.3, 6.4, -1.1]
]

print("Исходная матрица:")
print(np.array(matrix))

result = process_matrix(matrix)

print("\nНовая матрица:")
print(result)

Вариант 10
#######Найти максимальный среди всех элементов тех строк
заданной матрицы, которые упорядочены, (либо по возрастанию,
либо по убыванию).

import numpy as np

def find_max_in_ordered_rows(matrix):
    max_element = None
    rows, cols = matrix.shape

    for row_index in range(rows):
        row = matrix[row_index]
        if np.all(row[:-1] <= row[1:]):
            if max_element is None or np.max(row) > max_element:
                max_element = np.max(row)
        elif np.all(row[:-1] >= row[1:]):
            if max_element is None or np.max(row) > max_element:
                max_element = np.max(row)

    return max_element


matrix = np.array([
    [1, 2, 3, 4, 5],
    [5, 4, 3, 2, 1],
    [1, 3, 2, 4, 5],
    [10, 20, 30, 15, 5]
])

max_value = find_max_in_ordered_rows(matrix)

if max_value is not None:
    print(f"Максимальный элемент среди упорядоченных строк: {max_value}")
else:
    print("Упорядоченных строк не найдено.")

#######Расположить столбцы матрицы D[M, N] в порядке

возрастания элементов k-й строки (1 <= k)
import numpy as np

M, N = 4, 5
D = np.random.randint(0, 10, size=(M, N))
print("Исходная матрица D:")
print(D)

k = 0

sorted_indices = np.argsort(D[k])

sorted_D = D[:, sorted_indices]

print("\nМатрица D после сортировки столбцов по элементам k-й строки:")
print(sorted_D)


Вариант 11.
##########В данной действительной квадратной матрице порядка n
найти сумму элементов строки, в котором расположен элемент с
наименьшим значением. Предполагается, что такой элемент
единственный.

import numpy as np

n = 4 
matrix = np.random.randint(1, 100, size=(n, n))
print("Исходная матрица:")
print(matrix)

min_value = np.min(matrix)
min_index = np.where(matrix == min_value)

row_index = min_index[0][0]

row_sum = np.sum(matrix[row_index])

print(f"\nМинимальный элемент: {min_value} находится в строке {row_index + 1}")
print(f"Сумма элементов строки {row_index + 1}: {row_sum}")

######Среди столбцов заданной целочисленной матрицы, содержащих только такие элементы, 
которые по модулю не больше 10, найти столбец с минимальным произведением 
элементов и поменять его с соседним.

import numpy as np

np.random.seed(0)
rows, cols = 5, 6
matrix = np.random.randint(-15, 15, size=(rows, cols))
print("Исходная матрица:")
print(matrix)

valid_columns = np.all(np.abs(matrix) <= 10, axis=0)

products = []
for col in range(cols):
    if valid_columns[col]:
        product = np.prod(matrix[:, col])
        products.append((product, col))

if not products:
    print("Нет столбцов, содержащих элементы по модулю не больше 10.")
else:
    min_product_col_index = min(products, key=lambda x: x[0])[1]

    if min_product_col_index < cols - 1:
        matrix[:, [min_product_col_index, min_product_col_index + 1]] = matrix[:, [min_product_col_index + 1, min_product_col_index]]
    else:
        matrix[:, [min_product_col_index, min_product_col_index - 1]] = matrix[:, [min_product_col_index - 1, min_product_col_index]]

    print("\nМатрица после замены столбца с минимальным произведением:")
    print(matrix)

Вариант 12
##########Среди столбцов заданной целочисленной матрицы, содержащих только такие элементы, 
которые по модулю не больше 10, найти столбец 
с минимальным произведением элементов и поменять его с соседним.

import numpy as np

np.random.seed()
n = 5
matrix = np.array([[1, 3, 3, 4, 5],
                   [2, 6, 7, 8, 9],
                   [3, 7, 3, 10, 11],
                   [4, 8, 10, 4, 12],
                   [5, 9, 11, 12, 5]])
print("Исходная матрица:")
print(matrix)

matching_indices = []
for k in range(n):
    if np.array_equal(matrix[k], matrix[:, k]):
        matching_indices.append(k)

if matching_indices:
    print(f"\nИндексы k, для которых k-я строка совпадает с k-м столбцом: {matching_indices}")
else:
    print("\nНет индексов k, для которых k-я строка совпадает с k-м столбцом.")

##########Дана действительная матрица размером n х m. Требуется
преобразовать матрицу: поэлементно вычесть последнюю строку из
всех строк, кроме последней.

import numpy as np

n, m = 5, 4

matrix = np.random.randint(1, 10, size=(n, m))
print("Исходная матрица:")
print(matrix)

matrix[:-1] = matrix[:-1] - matrix[-1]

print("\nПреобразованная матрица:")
print(matrix)

Вариант 13

######### Определить наименьший элемент каждой четной строки матрицы A[M, N]

import numpy as np

A = np.array([[5, 2, 9],
              [1, 4, 3],
              [8, 7, 6],
              [0, 5, 2],
              [3, 1, 4]])

M, N = A.shape

min_elements = []

for i in range(M):
    if i % 2 == 0:
        min_element = np.min(A[i])
        min_elements.append(min_element)
        
print("Наименьшие элементы четных строк:")
for min_elem in min_elements:
    print(min_elem)

######### Найти наибольший и наименьший элементы прямоугольной матрицы и поменять местами

import numpy as np

A = np.array([[5, 2, 9],
              [1, 4, 3],
              [8, 7, 6],
              [0, 5, 2]])

min_value = A[0, 0]
max_value = A[0, 0]
min_index = (0, 0)
max_index = (0, 0)

for i in range(A.shape[0]):
    for j in range(A.shape[1]):
        if A[i, j] < min_value:
            min_value = A[i, j]
            min_index = (i, j)
        if A[i, j] > max_value:
            max_value = A[i, j]
            max_index = (i, j)

A[min_index], A[max_index] = A[max_index], A[min_index]

print("Изменённая матрица:\n", A)

Вариант 14 
######## Задана квадратная матрица, переставить стоку с максимальным элементом на главной диагонали
со строкой с заданнным номером m 

import numpy as np

A = np.array([[5, 2, 9],
              [1, 4, 3],
              [8, 7, 6]])

m = 1

if m < 0 or m >= A.shape[0]:
    print("Номер строки m вне допустимых границ.")
else:
    max_value = A[0, 0]
    max_index = 0

    for i in range(A.shape[0]):
        if A[i, i] > max_value:
            max_value = A[i, i]
            max_index = i

    A[max_index], A[m] = A[m], A[max_index]

    print("Изменённая матрица:\n", A)


####### Составить программу которая заполняет квадратную матрицу порядка n натуральными числами
записывая их в нее по спирали

import numpy as np


def fill_spiral_matrix(n):
    matrix = np.zeros((n, n), dtype=int)

    left, right = 0, n - 1
    top, bottom = 0, n - 1
    num = 1

    while left <= right and top <= bottom:
        for i in range(left, right + 1):
            matrix[top, i] = num
            num += 1
        top += 1

        for i in range(top, bottom + 1):
            matrix[i, right] = num
            num += 1
        right -= 1

        if top <= bottom:
            for i in range(right, left - 1, -1):
                matrix[bottom, i] = num
                num += 1
            bottom -= 1

        if left <= right:
            for i in range(bottom, top - 1, -1):
                matrix[i, left] = num
                num += 1
            left += 1

    return matrix


n = 4
spiral_matrix = fill_spiral_matrix(n)

print(spiral_matrix)

Вариант 15
############### Определить номер сток матрицы R[M, N] хотя бы один элемент который которых равен
c, и элемент строки умножить на d

import numpy as np

def modify_matrix(R, c, d):
    for i in range(R.shape[0]):
        if c in R[i]:
            R[i] *= d
            return i, R
    return -1, R

R = np.array([[5, 2, 9],
              [1, 4, 3],
              [8, 7, 6],
              [0, 5, 2]])

c = 4
d = 3

row_index, modified_matrix = modify_matrix(R, c, d)

if row_index != -1:
    print(f"Номер строки, содержащей элемент {c}: {row_index}")
else:
    print(f"Элемент {c} не найден в матрице.")
print("Изменённая матрица:")
print(modified_matrix)

######## Среди тех строк целочисленной матрицы, которые содержат только нечетные
элементы, найти строку с максимальной суммой модулей элементов

import numpy as np


def find_row_with_max_odd_sum(matrix):
    max_sum = -1
    max_row_index = -1

    for i in range(matrix.shape[0]):
        row = matrix[i]

        if np.all(row % 2 != 0):
            current_sum = np.sum(np.abs(row))

            if current_sum > max_sum:
                max_sum = current_sum
                max_row_index = i

    return max_row_index, max_sum

matrix = np.array([[1, 3, 5],
                   [2, 4, 6],
                   [7, 9, 11],
                   [1, -3, 5],
                   [0, 2, 4]])

row_index, max_sum = find_row_with_max_odd_sum(matrix)

if row_index != -1:
    print(f"Номер строки с максимальной суммой модулей нечетных элементов: {row_index}")
    print(f"Максимальная сумма: {max_sum}")
else:
    print("Нет строк, содержащих только нечетные элементы.")
