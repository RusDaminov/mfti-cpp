#include <iostream>
#include <cmath> // для M_PI и pow
using namespace std;

int main() {
    double r = 3.0;
    double V = (4.0 / 3.0) * M_PI * pow(r, 3);

    cout.precision(15); // точность вывода
    cout << "Объём шара: " << fixed << V << endl;

    return 0;
}
