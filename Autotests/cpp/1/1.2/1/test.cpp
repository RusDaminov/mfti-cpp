#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

// Функция для тестирования программы
void runTest(const string& testName, const string& input, const string& expectedOutput) {
    // Сохраняем оригинальные потоки
    streambuf* originalCin = cin.rdbuf();
    streambuf* originalCout = cout.rdbuf();
    
    // Создаем строковые потоки для тестирования
    istringstream testInput(input);
    ostringstream testOutput;
    
    // Перенаправляем потоки
    cin.rdbuf(testInput.rdbuf());
    cout.rdbuf(testOutput.rdbuf());
    
    // Запускаем тестируемую программу
    string name;
    cout << "Введите ваше имя: ";
    cin >> name;
    cout << "Привет, " << name << "!" << endl;
    
    // Получаем результат
    string actualOutput = testOutput.str();
    
    // Восстанавливаем потоки
    cin.rdbuf(originalCin);
    cout.rdbuf(originalCout);
    
    // Проверяем результат
    if (actualOutput == expectedOutput) {
        cout << "✓ Тест '" << testName << "' пройден" << endl;
    } else {
        cout << "✗ Тест '" << testName << "' провален" << endl;
        cout << "Ожидалось: '" << expectedOutput << "'" << endl;
        cout << "Получено: '" << actualOutput << "'" << endl;
    }
}

int main() {
    cout << "Запуск автотестов для программы приветствия..." << endl;
    cout << "=============================================" << endl;
    
    // Тест 1: Обычное русское имя
    runTest("Русское имя", "Анна", 
            "Введите ваше имя: Привет, Анна!\n");
    
    // Тест 2: Английское имя
    runTest("Английское имя", "John", 
            "Введите ваше имя: Привет, John!\n");
    
    // Тест 3: Имя с цифрами
    runTest("Имя с цифрами", "User123", 
            "Введите ваше имя: Привет, User123!\n");
    
    // Тест 4: Короткое имя
    runTest("Короткое имя", "А", 
            "Введите ваше имя: Привет, А!\n");
    
    // Тест 5: Имя из одного символа
    runTest("Однобуквенное имя", "B", 
            "Введите ваше имя: Привет, B!\n");
    
    cout << "=============================================" << endl;
    cout << "Тестирование завершено!" << endl;
    
    return 0;
}