#include <iostream>
using namespace std;

int main() {
    int integer;
    double floating;
    string text;
    
    cout << "Введите целое число: ";
    cin >> integer;
    
    cout << "Введите вещественное число: ";
    cin >> floating;
    
    // Обратите внимание: cin не читает пробелы, поэтому нужно очистить буфер
    cin.ignore(); // Удаляем символ новой строки
    getline(cin, text); // Читаем всю строку
    
    cout << "Ваш ввод:" << endl;
    cout << "Целое: " << integer << endl;
    cout << "Вещественное: " << floating << endl;
    cout << "Строка: " << text << endl;
    
    return 0;
}
