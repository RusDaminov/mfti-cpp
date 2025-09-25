#include <iostream>
#include <cmath> // для sqrt()
using namespace std;

int main() {
    double a = 5.0;
    double b = 6.0;
    double c = 7.0;

    // Вычисление полупериметра
    double p = (a + b + c) / 2.0;

    // Вычисление площади по формуле Герона
    double S = sqrt(p * (p - a) * (p - b) * (p - c));

    cout.precision(15); // точность вывода
    cout << "Площадь треугольника: " << fixed << S << endl;

    return 0;
}
