#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double E;

    // Ввод погрешности
    cout << "enter pogres6nost E: ";
    cin >> E;

    double S = 0.0;  // Сумма ряда
    double term;     // Текущий член ряда
    int i = 1;       // Номер члена ряда
    int sign = 1;    // Знак члена (+1 или -1)

    do {
        // Вычисляем текущий член ряда
        term = sign * 1.0 / (i * (i + 1) * (i + 2));

        // Добавляем член к сумме
        S += term;

        // Выводим информацию о текущей итерации
        cout << i << "\t" << scientific << setprecision(6) << term;
        cout << "\t" << fixed << setprecision(10) << S << endl;

        // Меняем знак для следующего члена
        sign = -sign;
        i++;

    } while (abs(term) >= E);  // Продолжаем, пока член не станет меньше E

    // Вывод результата
    cout << "\nresult:" << endl;
    cout << "suma r1da S = " << fixed << setprecision(15) << S << endl;
    cout << "Number of summed : " << i - 1 << endl;
    cout << "pogres6nost E = " << scientific << E << endl;

    return 0;
}