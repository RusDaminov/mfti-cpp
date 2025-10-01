#include <iostream>
#include <algorithm> // для std::min
using namespace std;

int main() {
    int a, b, c;
    
    cout << "Введите a: ";
    cin >> a;
    
    cout << "Введите b: ";
    cin >> b;
    
    cout << "Введите c: ";
    cin >> c;

    int val1 = 4 * a;
    int val2 = 2 * b + 1;
    int val3 = 4 * c + 2;

    int result = min(val1, min(val2, val3));

    cout << "Минимальное значение: " << result << endl;

    return 0;
}
