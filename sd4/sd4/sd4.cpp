#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    double E;

    cout << "enter E: ";
    cin >> E;


    if (E <= 0) {
        cout << "erorr (E > 0)" << endl;
        return 1;
    }

    double S = 0.0;     
    double term;         
    int i = 1; // Номер текущего члена
    int sign = 1;       
    int count = 0;      

    do {
        term = sign * 1.0 / (i * (i + 1) * (i + 2));
        S += term;
        sign = -sign;
        i++;
        count++;

    } while (abs(term) >= E);  // бесконечно пока член не стант E

    cout << " S = " << fixed << setprecision(15) << S << endl;
    cout << "koli4estvo: " << count << endl;
    cout << "pogres6nost: " << setprecision(1) << E << endl;
    cout << "posledni 4len: " << setprecision(6) << abs(term) << endl;

    return 0;
}