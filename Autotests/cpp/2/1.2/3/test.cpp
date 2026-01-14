#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iomanip>

struct TestCase {
    std::string input;
    char expected;
    std::string description;
};

bool run_program(const std::string& exe_name, const std::string& input, std::string& output) {
    // Создаём временный файл для ввода
    std::ofstream in_file("temp_input.txt");
    in_file << input;
    in_file.close();

    // Формируем команду: ./program < temp_input.txt
    std::string command;
#ifdef _WIN32
    command = exe_name + ".exe < temp_input.txt > temp_output.txt 2> nul";
#else
    command = "./" + exe_name + " < temp_input.txt > temp_output.txt 2>/dev/null";
#endif

    int result = std::system(command.c_str());
    if (result != 0) {
        output = "";
        return false;
    }

    // Читаем вывод
    std::ifstream out_file("temp_output.txt");
    if (!out_file) {
        output = "";
        return false;
    }
    std::getline(out_file, output);
    // Убираем возможные переводы строки в конце
    if (!output.empty() && output.back() == '\r') output.pop_back();
    if (!output.empty() && output.back() == '\n') output.pop_back();

    out_file.close();
    return true;
}

void cleanup() {
#ifdef _WIN32
    std::system("del temp_input.txt temp_output.txt 2>nul");
    std::system("del program.exe 2>nul");
#else
    std::system("rm -f temp_input.txt temp_output.txt program");
#endif
}

int main() {
    // Список тестов
    std::vector<TestCase> tests = {
        {"abracadabra", 'a', "Пример из условия"},
        {"a", 'a', "Строка из одного символа"},
        {"abc", 'a', "Все символы уникальны — первый"},
        {"aaabbb", 'a', "a и b по 3 раза — a встречается раньше"},
        {"bbbaaa", 'b', "b и a по 3 раза — b встречается раньше"},
        {"zzzzz", 'z', "Все символы одинаковые"},
        {"aabbcc", 'a', "По 2 раза каждый — первый a"},
        {"programming", 'r', "programming → r встречается 3 раза, остальные меньше"},
        {"", ' ', "Пустая строка — по условию не обещана, но на всякий случай"}
    };

    // Попытка компиляции
    std::string compile_cmd;
#ifdef _WIN32
    compile_cmd = "g++ main.cpp -o program.exe -O2 -std=c++17";
    if (std::system("where g++ >nul 2>&1") != 0) {
        // Попробуем clang++
        compile_cmd = "clang++ main.cpp -o program.exe -O2 -std=c++17";
    }
#else
    compile_cmd = "g++ main.cpp -o program -O2 -std=c++17";
#endif

    std::cout << "Компиляция main.cpp...\n";
    int compile_result = std::system(compile_cmd.c_str());

    if (compile_result != 0) {
        std::cout << "Ошибка компиляции! Код не скомпилировался.\n";
        return 1;
    }

    std::cout << "Компиляция успешна. Запуск тестов...\n\n";

    bool all_passed = true;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& t = tests[i];

        // Пропустим тест с пустой строкой, если программа может упасть (s[0] при пустой строке)
        if (t.input.empty()) {
            std::cout << "Тест " << (i+1) << " (пустая строка): пропущен (не по условию задачи)\n";
            continue;
        }

        std::string output;
        bool ok = run_program("program", t.input, output);

        std::cout << "Тест " << (i+1) << ": " << std::quoted(t.description) << "\n";
        std::cout << "  Ввод: \"" << t.input << "\"\n";
        std::cout << "  Ожидалось: '" << t.expected << "'\n";

        if (!ok) {
            std::cout << "  Результат: программа завершилась с ошибкой\n";
            all_passed = false;
        } else if (output.length() != 1 || output[0] != t.expected) {
            std::cout << "  Результат: '" << (output.empty() ? "<пусто>" : output) << "' ← НЕВЕРНО\n";
            all_passed = false;
        } else {
            std::cout << "  Результат: '" << output << "' ← ОК\n";
        }
        std::cout << "\n";
    }

    cleanup();

    if (all_passed) {
        std::cout << "Все тесты пройдены успешно!\n";
        return 0;
    } else {
        std::cout << "Есть ошибки в некоторых тестах.\n";
        return 1;
    }
}