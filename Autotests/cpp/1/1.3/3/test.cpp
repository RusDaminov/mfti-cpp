#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;

// Функция для чтения всего файла в строку
string readFile(const string& filename) {
    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    // === 1. Проверка наличия корректной формулы ===
    string code = readFile("main.cpp");

    bool hasCorrectFormula = (
        code.find("(4.0 / 3.0)") != string::npos ||
        code.find("(4.0/3.0)") != string::npos ||
        code.find("(4 / 3)") != string::npos
    );

    if (!hasCorrectFormula) {
        cerr << "❌ Ошибка: неверная формула. Ожидалось (4.0 / 3.0) * M_PI * pow(r, 3)" << endl;
        return 1;
    }

    cout << "✅ Формула найдена корректно" << endl;

    // === 2. Компиляция main.cpp ===
    int compileStatus = system("g++ -std=c++11 -w main.cpp -o main");
    if (compileStatus != 0) {
        cerr << "❌ Ошибка компиляции main.cpp" << endl;
        return 1;
    }
    cout << "✅ Компиляция прошла успешно" << endl;

    // === 3. Запуск и проверка результата ===
    FILE* pipe = popen("./main", "r");
    if (!pipe) {
        cerr << "❌ Не удалось запустить main" << endl;
        return 1;
    }

    char buffer[256];
    string output;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
        output += buffer;
    pclose(pipe);

    cout << "Вывод программы:\n" << output << endl;

    // === 4. Проверка значения ===
    double expected = (4.0 / 3.0) * M_PI * pow(3.0, 3);
    double found = 0.0;

    // Ищем число в выводе
    stringstream ss(output);
    string word;
    while (ss >> word) {
        try {
            found = stod(word);
            break;
        } catch (...) {}
    }

    double diff = fabs(found - expected);
    if (diff < 1e-6)
        cout << "✅ Результат корректный: " << found << endl;
    else {
        cerr << "❌ Ошибка в результате. Ожидалось " << expected << ", получено " << found << endl;
        return 1;
    }

    cout << "🎯 Тест пройден успешно!" << endl;
    return 0;
}
