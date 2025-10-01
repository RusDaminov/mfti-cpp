#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

void testAdditionProgram() {
    struct TestCase {
        int a;
        int b;
        int expected;
    };
    
    TestCase tests[] = {
        {2, 2, 4},
        {-1, 1, 0},
        {0, 0, 0},
        {100, 200, 300},
        {-10, -20, -30},
        {5, -3, 2}
    };
    
    cout << "Запуск минималистичных тестов...\n";
    
    for (const auto& test : tests) {
        // Перенаправляем потоки
        streambuf* origCin = cin.rdbuf();
        streambuf* origCout = cout.rdbuf();
        
        stringstream input;
        input << test.a << "\n" << test.b << "\n";
        
        ostringstream output;
        
        cin.rdbuf(input.rdbuf());
        cout.rdbuf(output.rdbuf());
        
        // Выполняем программу
        int a, b;
        cout << "Введите первое число: ";
        cin >> a;
        cout << "Введите второе число: ";
        cin >> b;
        int result = a + b;
        cout << "Сумма: " << result << endl;
        
        // Восстанавливаем потоки
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
        
        // Проверяем
        assert(result == test.expected);
        cout << "✓ " << test.a << " + " << test.b << " = " << test.expected << endl;
    }
    
    cout << "Все тесты пройдены!\n";
}

int main() {
    testAdditionProgram();
    return 0;
}