1|||||||
print('школька')
parameters = {'1a': 6, '1b': 28, '2v': 42, '3z': 3, '3f': 31}

while True:
    school = input('какой класс: ')
    if not school.isalnum():
        print("Ошибка: только буквы и цифры.")
        continue
    try:
        print(parameters[school])
        break
    except KeyError:
        print("Ошибка: нет такого класса.")
        break

2||||
Z= {1:'a', 2:'a', 3:'a', 4:'a'}
x = Z.items()
print(x) 

3||||
print('школька')
parameters = {'1a': 6, '1b': 28, '2v': 42, '3z': 3, '3f': 31}
parameters.update(
    {'1a': 123123,
     '3z': 3213,
     '3f': 234423423
    }
)
while True:
    school = input('какой класс: ')
    if not school.isalnum():
        print("Ошибка: только буквы и цифры.")
        continue
    try:
        print(parameters[school])
        break
    except KeyError:
        print("Ошибка: нет такого класса.")
        break

4||||||
a = {
    'cat': 'кошка',
    'dog': 'собака',
    'mouse': 'мышь',
    'house': 'дом',
    'eats': 'ест',
    'in': 'в',
    'too': 'тоже',
}

def translate_text(text):
    words = text.split()
    translated_words = [a.get(word, word) for word in words]
    return ' '.join(translated_words)

b = input('Введите текст')
translated_text = translate_text(b)
print(translated_text)

5|||||||
print('школька')
parameters = {'1a': 6, '1b': 28, '2v': 42, '3z': 3, '3f': 31}
parameters['9e'] = 1

while True:
    school = input('какой класс: ')
    if not school.isalnum():
        print("Ошибка: только буквы и цифры.")
        continue
    try:
        print(parameters[school])
        break
    except KeyError:
        print("Ошибка: нет такого класса.")
        break

6|||||
print('школька')
parameters = {'1a': 6, '1b': 28, '2v': 42, '3z': 3, '3f': 31}
del parameters['1a']

while True:
    school = input('какой класс: ')
    if not school.isalnum():
        print("Ошибка: только буквы и цифры.")
        continue
    try:
        print(parameters[school])
        break
    except KeyError:
        print("Ошибка: нет такого класса.")
        break

7|||||||
from collections import Counter
import re

def count_words(text):
    text = text.lower()
    
    words = re.findall(r'\b\w+\b', text)

    word_counts = Counter(words)

    most_common_words = word_counts.most_common(10)

    return most_common_words


text = "В рамках спецификации современных стандартов,активно развивающиеся страны третьего мира, инициированные исключительно синтетически, объединены в целые кластеры себе подобных! Идейные соображения высшего порядка, а такжесуществующая теория прекрасно подходит для реализации вывода текущих активов. Ясность нашей позиции очевидна: сплочённость команды профессионалов однозначно определяет каждого участника как способного принимать собственные решения касаемо укрепления моральных ценностей."

result = count_words(text)
for word, count in result:
    print(f"Слово: '{word}' - Количество вхождений: {count}")

8||||||
print('школька')
parameters = {'1a': 6, '1b': 28, '2v': 42, '3z': 3, '3f': 31}

total = sum(parameters.values())
print(total)

9||||||||
print('выбери страну')
parameters = {'россия': 'русcком', 'украина': 'русском', 'сша': 'на предательском', 'египет': 'арабский', 'германия': 'нерусский'}
keys_list = list(parameters.keys())
print(keys_list)
school = input('')
print(parameters[school])

10|||||||
parameters = {
    'cat': 'кошка',
    'dog': 'собака',
    'mouse': 'мышь',
    'house': 'дом',
    'eats': 'ест',
    'in': 'в',
    'too': 'тоже',
}

inverted = {value: key for key, value in parameters.items()}

print(inverted)

11|||||
from collections import defaultdict

def count_characters(input_string):
    counts = defaultdict(int)
    for char in input_string:
        counts[char] += 1
    result = defaultdict(list)
    for char, count in counts.items():
        result[count].append(char)
    return dict(result)

input_string = "heuhhhhhhhha "
output = count_characters(input_string)

print(output)

12||||||
games = {
    "Cyberpunk 2077": 18,
    "Minecraft": 7,
    "Grand Theft Auto V": 17,
    "The Witcher 3: Wild Hunt": 18,
    "Stardew Valley": 10,
    "Animal Crossing: New Horizons": 3,
    "Red Dead Redemption 2": 17
}

sorted_games = dict(sorted(games.items()))

for game, age_rating in sorted_games.items():
    print(f"{game} = {age_rating}+")

13||||
voc = {'horse': 'лошадь',
       'car': 'машина',
       'path': 'путь'}
voc1 = {j: i for i, j in voc.items()}
n = input()
try:
    print (voc[n])
except KeyError:
    try:
        print (voc1[n])
    except KeyError:
        print ('Данного слова нет в словаре')
