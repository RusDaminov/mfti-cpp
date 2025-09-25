#include <iostream>
#include <cmath> // Для sqrt()
using namespace std;

int main() {
    double x1 = 1.0;
    double y1 = 2.0;
    double x2 = 4.0;
    double y2 = 6.0;

    // Вычисление расстояния между точками
    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Вывод результата
    cout << "Расстояние между точками: " << d << endl;

    return 0;
}
