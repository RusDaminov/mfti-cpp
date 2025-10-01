#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

// Функция для запуска программы с входными данными и получения результата
std::string runProgram(const std::string& program, const std::string& input) {
    // Записываем входные данные в файл
    std::ofstream inputFile("input.txt");
    inputFile << input;
    inputFile.close();
    
    // Запускаем программу
    std::string command = program + " < input.txt > output.txt";
    system(command.c_str());
    
    // Читаем результат
    std::ifstream outputFile("output.txt");
    std::string result;
    std::getline(outputFile, result);
    outputFile.close();
    
    return result;
}

// Функция для вычисления ожидаемого результата по формуле
long long calculateExpected(int n, int m) {
    long long x_pairs = (long long)n * (n + 1) / 2;
    long long y_pairs = (long long)m * (m + 1) / 2;
    return x_pairs * y_pairs;
}

// Функция для тестирования одной программы
void testProgram(const std::string& programName, const std::vector<std::pair<int, int>>& testCases) {
    std::cout << "Тестирование " << programName << ":\n";
    std::cout << "========================================\n";
    
    int passed = 0;
    int total = testCases.size();
    
    for (size_t i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        int m = testCases[i].second;
        
        std::stringstream input;
        input << n << " " << m;
        
        std::string resultStr = runProgram(programName, input.str());
        long long result = std::stoll(resultStr);
        long long expected = calculateExpected(n, m);
        
        std::cout << "Тест " << (i + 1) << ": N=" << n << ", M=" << m << "\n";
        std::cout << "  Ожидаемый результат: " << expected << "\n";
        std::cout << "  Полученный результат: " << result << "\n";
        
        if (result == expected) {
            std::cout << "  ✓ ПРОЙДЕН\n";
            passed++;
        } else {
            std::cout << "  ✗ НЕ ПРОЙДЕН\n";
        }
        std::cout << "----------------------------------------\n";
    }
    
    std::cout << "Итог: " << passed << "/" << total << " тестов пройдено\n";
    std::cout << "========================================\n\n";
}

int main() {
    // Тестовые случаи
    std::vector<std::pair<int, int>> testCases = {
        {2, 2},    // Должно быть 9
        {2, 3},    // Должно быть 18
        {3, 2},    // Должно быть 18  
        {3, 3},    // Должно быть 36
        {1, 1},    // Должно быть 1
        {1, 5},    // Должно быть 15
        {5, 1},    // Должно быть 15
        {10, 10},  // Должно быть 3025
        {100, 100},// Должно быть 25502500
        {75000, 1} // Крайний случай
    };
    
    // Тестируем разные версии программ
    testProgram("./main_slow", testCases);    // 4-цикловая версия (40 баллов)
    testProgram("./main_medium", testCases);  // 2-цикловая версия (70 баллов)  
    testProgram("./main_fast", testCases);    // O(1) версия (100 баллов)
    
    return 0;
}