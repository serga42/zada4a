import math

# соси
mode = "degrees" 

def emnogenie(a, b):
    return a * b

def delenie(a, b):
    return a / b

def vicitan(a, b):
    return a - b

def slog(a, b):
    return a + b

def procent(a):
    return a / 100

def coren(a):
    if a < 0:
        print("Ошибка! ты елаби лузер")
    return math.sqrt(a)

def stepen(a, b):
  return a**b

def inv(a):
    return 1/a

def expfunc(a):
  return math.exp(a)

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def logariphm(a, base=10):
    return math.log(a, base)


def change_sign(a):
  #смена хуйни ну тут чтобы орентироваться я написал 
  return -a

def sinus(a):
    global mode
    if mode == "degrees":
        return math.sin(math.radians(a)) # при смене режимов мочи на говно
    else:
        return math.sin(a)

def cosinus(a):
    global mode
    if mode == "degrees":
        return math.cos(math.radians(a))  # при смене режимов мочи на говно
    else:
        return math.cos(a)

def tangens(a):
    global mode
    if mode == "degrees":
        return math.tan(math.radians(a))   # при смене режимов мочи на говно
    else:
        return math.tan(a)

def sinhfunc(a):
    return math.sinh(a)

def coshfunc(a):
    return math.cosh(a)

def tanhfunc(a):
    return math.tanh(a)

# переключение между мочей и саньей
def toggle_mode():
    global mode
    if mode == "degrees":
        mode = "radians"
        print("Режим радианы.")
    else:
        mode = "degrees"
        print("Режим градусы.")


while True:
    print(f"\nТекущий режим: {mode}")
    print("Выберите операцию:")
    print("1) умножение")
    print("2) деление")
    print("3) вычитание")
    print("4) сложение")
    print("5) %")
    print("6) √")
    print("7) x^y")
    print("8) 1/x (инверсия)")
    print("9) exp")
    print("10) n! (факториал)")
    print("11) log10 (десятичный логарифм)")
    print("12) смена знака (+/-)")
    print("13) sin(x)")
    print("14) cos(x)")
    print("15) tan(x)")
    print("16) sinh(x)")
    print("17) cosh(x)")
    print("18) tanh(x)")
    print("19) Переключить режим градусы/радианы")

    print("0) Выход\n")

    vibor = input("выбери вариант: ")

    if vibor == '0':
        break

    try:
        if vibor in ('1', '2', '3', '4', '7'):
            a = float(input("введите 1 число: "))
            b = float(input("введите 2 число: "))
        elif vibor in ('5', '6', '8','9','10','11','12', '13', '14', '15', '16', '17', '18'):
            a = float(input("введите число: "))
        elif vibor == '19':
            toggle_mode()
            continue  
        else:
            print("Неверный выбор")
            continue

        if vibor == '1':
            result = emnogenie(a, b)
        elif vibor == '2':
            result = delenie(a, b)
        elif vibor == '3':
            result = vicitan(a, b)
        elif vibor == '4':
            result = slog(a, b)
        elif vibor == '5':
            result = procent(a)
        elif vibor == '6':
            result = coren(a)
        elif vibor =='7':
            result = stepen(a,b)
        elif vibor =='8':
          result = inv(a)
        elif vibor == '9':
          result = expfunc(a)
        elif vibor == '10':
            result = factorial(a)
        elif vibor == '11':
            result = logariphm(a)
        elif vibor == '12':
            result = change_sign(a)
        elif vibor == '13':
            result = sinus(a)
        elif vibor == '14':
            result = cosinus(a)
        elif vibor == '15':
            result = tangens(a)
        elif vibor == '16':
            result = sinhfunc(a)
        elif vibor == '17':
            result = coshfunc(a)
        elif vibor == '18':
            result = tanhfunc(a)
        else:
            result = None

        if result is not None: 
            print(result)

    except ValueError:
        print("Ошибка! Введите число, а не строку еблан")

print("Пока!")