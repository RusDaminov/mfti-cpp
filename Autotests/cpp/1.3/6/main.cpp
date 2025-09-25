#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    
    cout << "Введите a: ";
    cin >> a;
    
    cout << "Введите b: ";
    cin >> b;
    
    cout << "Введите c: ";
    cin >> c;

    int denominator = 3 * a + 2 * b;

    if (denominator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
    } else {
        int ans = c / denominator;
        cout << "Результат: " << ans << endl;
    }

    return 0;
}
