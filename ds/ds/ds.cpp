#include <iostream>
#include <iomanip> // setprecision

using namespace std;

int main() {
    const int size = 100; 
    double arr[size];     
    int n;                

    cout << "Enter number of array elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    double average = sum / n;

    int lastPositiveIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            lastPositiveIndex = i;
        }
    }

    cout << "\nResults:" << endl;
    cout << "Sum of elements: " << sum << endl;
    cout << "Arithmetic mean: " << fixed << setprecision(2) << average << endl;

    if (lastPositiveIndex != -1) {
        cout << "Last positive element: " << arr[lastPositiveIndex]
            << " (index " << lastPositiveIndex << ")" << endl;

        arr[lastPositiveIndex] = average;

        cout << "Modified array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
    else {
        cout << "No positive elements in array." << endl;
        cout << "Original array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}