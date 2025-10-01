#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int integer;
    double floating;
    bool logical;
    
    cout << "Введите целое число: ";
    cin >> integer;
    
    cout << "Введите вещественное число: ";
    cin >> floating;
    
    cout << "Введите логическое значение (0/1): ";
    cin >> logical;
    
    cout << "Целое: " << integer << endl;
    cout << "Вещественное: " << fixed << setprecision(2) << floating << endl;
    cout << "Логическое: " << (logical ? "true" : "false") << endl;
    
    return 0;
}