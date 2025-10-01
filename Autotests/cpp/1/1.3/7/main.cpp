#include <iostream>
using namespace std;

int main() {
    int n, k;
    
    cout << "Введите n: ";
    cin >> n;
    
    cout << "Введите k: ";
    cin >> k;

    if (k == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 1;
    }

    int result = 2 * n * (n / k - 1);  // n / k — целочисленное деление в C++
    cout << "Результат: " << result << endl;

    return 0;
}
