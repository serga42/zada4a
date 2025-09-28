#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    const double alpha = 2.34e-2;
    double x;

    cout << "enter x: ";
    cin >> x;

    if (x <= 0) {
        cout << "y4i matimatiky eblan" << endl;
        return 1;
    }

    double sin_x = sin(x);
    double cos_x = cos(x);
    double denominator = sin_x * cos_x;

    if (abs(denominator) < 1e-10) {
        cout << "erorr - sin(x)cos(x) = 0" << endl;
        return 1;
    }
    double part1 = pow(x, 4) * log(x);
    double part2_numerator = pow(x, alpha) * exp(alpha * x);
    double part2 = part2_numerator / denominator;
    double y = part1 + part2;

  //cout << fixed << setprecision(6);
  //cout << "x = " << x << endl;
  //cout << "α = " << scientific << alpha << endl;
  //cout << "x⁴ = " << pow(x, 4) << endl;
  //cout << "ln x = " << log(x) << endl;
  //cout << "1 4ast: x⁴ ln x = " << part1 << endl;
  //cout << "xᵃ = " << pow(x, alpha) << endl;
  //cout << "eᵃˣ = " << exp(alpha * x) << endl;
  //cout << "4islitek 2 4asti: xᵃ · eᵃˣ = " << part2_numerator << endl;
  //cout << "sin x cos x = " << denominator << endl;
  //cout << "2 4ast: (xᵃ · eᵃˣ)/(sin x cos x) = " << part2 << endl;
    cout << "y = " << y << endl;

    return 0;
}