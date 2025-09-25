#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name;
    int age;
    double average_score;
    
    cout << "Введите ваше имя: ";
    cin >> name;
    
    cout << "Введите ваш возраст: ";
    cin >> age;
    
    cout << "Введите ваш средний балл: ";
    cin >> average_score;
    
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;
    cout << fixed << setprecision(2);
    cout << "Средний балл: " << average_score << endl;
    
    return 0;
}
