#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

void testMultiTypeProgram() {
    struct TestData {
        string testName;
        int intVal;
        double doubleVal;
        bool boolVal;
    };
    
    TestData testCases[] = {
        {"Тест 1: Положительные значения", 42, 3.14159, true},
        {"Тест 2: Отрицательные значения", -15, -2.5, false},
        {"Тест 3: Нулевые значения", 0, 0.0, false},
        {"Тест 4: Большие числа", 1000000, 12345.6789, true},
        {"Тест 5: Дробное округление", 1, 9.999, true}
    };
    
    cout << "Запуск тестов программы с разными типами данных\n";
    cout << "==============================================\n";
    
    for (const auto& test : testCases) {
        // Сохраняем оригинальные потоки
        streambuf* origCin = cin.rdbuf();
        streambuf* origCout = cout.rdbuf();
        
        // Настраиваем тестовые потоки
        stringstream inputStream;
        inputStream << test.intVal << "\n" << test.doubleVal << "\n" << test.boolVal << "\n";
        
        ostringstream outputStream;
        
        cin.rdbuf(inputStream.rdbuf());
        cout.rdbuf(outputStream.rdbuf());
        
        // Запускаем программу
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
        
        // Получаем вывод
        string result = outputStream.str();
        
        // Восстанавливаем потоки
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
        
        // Проверяем корректность
        bool intCorrect = (integer == test.intVal);
        bool doubleCorrect = (floating == test.doubleVal);
        bool boolCorrect = (logical == test.boolVal);
        
        if (intCorrect && doubleCorrect && boolCorrect) {
            cout << "✓ " << test.testName << " - пройден" << endl;
            cout << "  Результат: " << integer << ", " << fixed << setprecision(2) << floating 
                 << ", " << (logical ? "true" : "false") << endl;
        } else {
            cout << "✗ " << test.testName << " - провален" << endl;
            cout << "  Ожидалось: " << test.intVal << ", " << test.doubleVal 
                 << ", " << (test.boolVal ? "true" : "false") << endl;
            cout << "  Получено: " << integer << ", " << floating 
                 << ", " << (logical ? "true" : "false") << endl;
        }
    }
    
    cout << "==============================================\n";
    cout << "Тестирование завершено!\n";
}

int main() {
    testMultiTypeProgram();
    return 0;
}