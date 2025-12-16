#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void testMixedInputProgram() {
    struct TestCase {
        string description;
        int intInput;
        double doubleInput;
        string stringInput;
    };
    
    TestCase testCases[] = {
        {"Обычные значения", 10, 3.14, "Hello World"},
        {"Строка с пробелами", 25, 99.99, "Это строка с несколькими словами"},
        {"Отрицательные числа", -5, -7.5, "Negative test"},
        {"Пустая строка", 0, 0.0, ""},
        {"Спецсимволы", 1, 1.0, "!@#$%^&*()"}
    };
    
    cout << "Тестирование программы с разными типами ввода\n";
    cout << "============================================\n";
    
    for (const auto& test : testCases) {
        // Сохраняем оригинальные потоки
        streambuf* origCin = cin.rdbuf();
        streambuf* origCout = cout.rdbuf();
        
        // Настраиваем тестовые потоки
        stringstream inputStream;
        inputStream << test.intInput << "\n" << test.doubleInput << "\n" << test.stringInput << "\n";
        
        ostringstream outputStream;
        
        cin.rdbuf(inputStream.rdbuf());
        cout.rdbuf(outputStream.rdbuf());
        
        // Запускаем программу
        int integer;
        double floating;
        string text;
        
        cout << "Введите целое число: ";
        cin >> integer;
        
        cout << "Введите вещественное число: ";
        cin >> floating;
        
        cin.ignore();
        getline(cin, text);
        
        cout << "Ваш ввод:" << endl;
        cout << "Целое: " << integer << endl;
        cout << "Вещественное: " << floating << endl;
        cout << "Строка: " << text << endl;
        
        // Получаем вывод
        string result = outputStream.str();
        
        // Восстанавливаем потоки
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
        
        // Проверяем корректность
        bool success = (integer == test.intInput) && 
                      (floating == test.doubleInput) && 
                      (text == test.stringInput);
        
        if (success) {
            cout << "✓ " << test.description << " - пройден" << endl;
            cout << "  Результат: " << integer << ", " << floating << ", \"" << text << "\"" << endl;
        } else {
            cout << "✗ " << test.description << " - провален" << endl;
            cout << "  Ожидалось: " << test.intInput << ", " << test.doubleInput << ", \"" << test.stringInput << "\"" << endl;
            cout << "  Получено: " << integer << ", " << floating << ", \"" << text << "\"" << endl;
        }
    }
    
    cout << "============================================\n";
    cout << "Тестирование завершено!\n";
}

int main() {
    testMixedInputProgram();
    return 0;
}