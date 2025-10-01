#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// Функция для проверки корректности рассадки
bool isValidSeating(const vector<int>& result, const vector<int>& input) {
    if (result.size() == 1 && result[0] == 0) {
        // Проверяем, действительно ли решение невозможно
        // Для этого проверяем условие: если какая-то школа имеет больше половины участников
        vector<int> freq(3001, 0);
        for (int school : input) {
            freq[school]++;
        }
        
        int maxCount = 0;
        for (int count : freq) {
            if (count > maxCount) {
                maxCount = count;
            }
        }
        
        return maxCount > (input.size() + 1) / 2;
    }
    
    // Проверяем, что результат - перестановка входных данных
    if (result.size() != input.size()) {
        return false;
    }
    
    vector<int> resultFreq(3001, 0);
    vector<int> inputFreq(3001, 0);
    
    for (int school : result) {
        resultFreq[school]++;
    }
    for (int school : input) {
        inputFreq[school]++;
    }
    
    for (int i = 1; i <= 3000; i++) {
        if (resultFreq[i] != inputFreq[i]) {
            return false;
        }
    }
    
    // Проверяем, что нет двух одинаковых школ подряд
    for (size_t i = 1; i < result.size(); i++) {
        if (result[i] == result[i - 1]) {
            return false;
        }
    }
    
    return true;
}

// Функция для запуска одного теста
void runTest(int testNumber, const vector<int>& input, const string& expectedStr) {
    cout << "Тест " << testNumber << ": ";
    
    // Создаем входные данные для программы
    stringstream inputStream;
    inputStream << input.size() << "\n";
    for (int school : input) {
        inputStream << school << "\n";
    }
    
    // Сохраняем оригинальные cin/cout
    streambuf* oldCin = cin.rdbuf();
    streambuf* oldCout = cout.rdbuf();
    
    // Перенаправляем ввод/вывод
    cin.rdbuf(inputStream.rdbuf());
    stringstream outputStream;
    cout.rdbuf(outputStream.rdbuf());
    
    // Запускаем основную программу
    extern int main();
    main();
    
    // Восстанавливаем cin/cout
    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);
    
    // Получаем результат
    string resultStr = outputStream.str();
    
    // Убираем лишние пробелы и переводы строк
    while (!resultStr.empty() && (resultStr.back() == '\n' || resultStr.back() == ' ')) {
        resultStr.pop_back();
    }
    
    // Парсим ожидаемый результат
    stringstream expectedStream(expectedStr);
    vector<int> expected;
    int num;
    while (expectedStream >> num) {
        expected.push_back(num);
    }
    
    // Если ожидается 0
    if (expected.size() == 1 && expected[0] == 0) {
        if (resultStr == "0") {
            cout << "ПРОЙДЕН" << endl;
        } else {
            cout << "НЕ ПРОЙДЕН" << endl;
            cout << "Ожидалось: 0" << endl;
            cout << "Получено: " << resultStr << endl;
        }
        return;
    }
    
    // Парсим полученный результат
    stringstream resultStream(resultStr);
    vector<int> result;
    while (resultStream >> num) {
        result.push_back(num);
    }
    
    // Проверяем корректность
    if (isValidSeating(result, input)) {
        cout << "ПРОЙДЕН" << endl;
    } else {
        cout << "НЕ ПРОЙДЕН" << endl;
        cout << "Входные данные: ";
        for (size_t i = 0; i < input.size(); i++) {
            if (i > 0) cout << " ";
            cout << input[i];
        }
        cout << endl;
        cout << "Ожидалось: " << expectedStr << endl;
        cout << "Получено: " << resultStr << endl;
    }
}

int main() {
    // Тест 1: Один участник
    runTest(1, {5}, "5");
    
    // Тест 2: Все участники из разных школ
    runTest(2, {1, 2, 3, 4}, "1 2 3 4");
    
    // Тест 3: Несколько участников из одних школ
    runTest(3, {1, 2, 1, 2, 3, 3}, "1 2 1 2 3 3");
    
    // Тест 4: Невозможная рассадка (две школы с одинаковым количеством участников, но всего 5 участников)
    runTest(4, {1, 1, 1, 2, 2}, "0");
    
    // Тест 5: Сложный случай с несколькими школами
    runTest(5, {2, 2, 2, 1, 1, 3, 4}, "2 1 2 1 2 3 4");
    
    cout << "\nТестирование завершено!" << endl;
    return 0;
}