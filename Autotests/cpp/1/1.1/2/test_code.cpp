#include <iostream>
#include <cassert>

using namespace std;

void testInput() {
    int input;
    cout << "Введите число 99443: ";
    cin >> input;
    
    assert(input == 99443);
    cout << "Тест пройден! Введено правильное число: " << input << endl;
}

int main() {
    testInput();
    return 0;
}