#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #include <sys/wait.h>
    #define CLEAR_SCREEN "clear"
#endif

class Tester {
private:
    std::string compiler;
    
public:
    Tester() {
        #ifdef _WIN32
            compiler = "g++";
        #else
            compiler = "g++";
        #endif
    }
    
    bool compile(const std::string& sourceFile, const std::string& outputFile) {
        std::string command = compiler + " -std=c++11 -o " + outputFile + " " + sourceFile;
        std::cout << "Компиляция: " << command << std::endl;
        
        int result = system(command.c_str());
        return (result == 0);
    }
    
    bool runTest(const std::string& program, const std::string& input, std::string& output) {
        #ifdef _WIN32
            // Windows implementation
            SECURITY_ATTRIBUTES sa;
            sa.nLength = sizeof(sa);
            sa.bInheritHandle = TRUE;
            sa.lpSecurityDescriptor = NULL;
            
            HANDLE hStdoutRead, hStdoutWrite;
            CreatePipe(&hStdoutRead, &hStdoutWrite, &sa, 0);
            SetHandleInformation(hStdoutRead, HANDLE_FLAG_INHERIT, 0);
            
            HANDLE hStdinRead, hStdinWrite;
            CreatePipe(&hStdinRead, &hStdinWrite, &sa, 0);
            SetHandleInformation(hStdinWrite, HANDLE_FLAG_INHERIT, 0);
            
            PROCESS_INFORMATION pi;
            STARTUPINFO si;
            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);
            si.dwFlags = STARTF_USESTDHANDLES;
            si.hStdInput = hStdinRead;
            si.hStdOutput = hStdoutWrite;
            si.hStdError = hStdoutWrite;
            
            std::string cmd = program + ".exe";
            BOOL success = CreateProcess(NULL, const_cast<LPSTR>(cmd.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
            
            if (!success) {
                std::cerr << "Ошибка запуска программы" << std::endl;
                return false;
            }
            
            DWORD written;
            WriteFile(hStdinWrite, input.c_str(), input.length(), &written, NULL);
            CloseHandle(hStdinWrite);
            
            CloseHandle(hStdoutWrite);
            
            WaitForSingleObject(pi.hProcess, INFINITE);
            
            char buffer[4096];
            DWORD read;
            output.clear();
            while (ReadFile(hStdoutRead, buffer, sizeof(buffer) - 1, &read, NULL) && read > 0) {
                buffer[read] = '\0';
                output += buffer;
            }
            
            CloseHandle(pi.hProcess);
            CloseHandle(pi.hThread);
            CloseHandle(hStdoutRead);
            CloseHandle(hStdinRead);
            
        #else
            // Unix/Linux implementation
            int stdin_pipe[2], stdout_pipe[2];
            pipe(stdin_pipe);
            pipe(stdout_pipe);
            
            pid_t pid = fork();
            
            if (pid == 0) {
                // Child process
                close(stdin_pipe[1]);
                close(stdout_pipe[0]);
                
                dup2(stdin_pipe[0], STDIN_FILENO);
                dup2(stdout_pipe[1], STDOUT_FILENO);
                dup2(stdout_pipe[1], STDERR_FILENO);
                
                close(stdin_pipe[0]);
                close(stdout_pipe[1]);
                
                execl(program.c_str(), program.c_str(), NULL);
                exit(1);
            } else {
                // Parent process
                close(stdin_pipe[0]);
                close(stdout_pipe[1]);
                
                write(stdin_pipe[1], input.c_str(), input.length());
                close(stdin_pipe[1]);
                
                char buffer[4096];
                output.clear();
                ssize_t count;
                while ((count = read(stdout_pipe[0], buffer, sizeof(buffer) - 1)) > 0) {
                    buffer[count] = '\0';
                    output += buffer;
                }
                
                close(stdout_pipe[0]);
                waitpid(pid, NULL, 0);
            }
        #endif
        
        // Убираем лишние пробелы и переводы строк
        size_t pos = output.find_last_not_of(" \n\r\t");
        if (pos != std::string::npos) {
            output = output.substr(0, pos + 1);
        }
        
        return true;
    }
    
    void runTests() {
        // Формат: {входные данные, ожидаемый результат}
        // Входные данные: "n S\ncoin1 coin2 ... coinN"
        std::vector<std::pair<std::string, std::string>> testCases = {
            {"3 4\n1 2 3", "4"},        // Сумма 4 монетами [1,2,3]: 1+1+1+1, 1+1+2, 2+2, 1+3
            {"2 5\n1 2", "3"},          // Сумма 5 монетами [1,2]: 1+1+1+1+1, 1+1+1+2, 1+2+2
            {"4 10\n2 5 3 6", "5"},     // Классический пример
            {"1 5\n3", "0"},            // Невозможно разменять
            {"1 6\n3", "1"},            // 3+3
            {"3 0\n1 2 3", "1"},        // Сумма 0 - 1 способ (не брать монеты)
            {"2 1\n1 2", "1"},          // Только 1
            {"2 2\n1 2", "2"},          // 1+1 или 2
            {"3 7\n1 2 5", "6"}         // Разные комбинации
        };
        
        std::cout << "Запуск тестов для задачи 'Подсчёт количества способов разменять сумму':\n";
        std::cout << "=====================================================================\n";
        
        int passed = 0;
        int total = testCases.size();
        
        for (size_t i = 0; i < testCases.size(); i++) {
            std::string input = testCases[i].first;
            std::string expected = testCases[i].second;
            std::string actual;
            
            std::cout << "Тест " << (i + 1) << ": Вход = \"" << input << "\"";
            std::cout << ", Ожидается = " << expected;
            
            if (runTest("main", input, actual)) {
                std::cout << ", Получено = " << actual;
                
                if (actual == expected) {
                    std::cout << " ✓ ПРОЙДЕН" << std::endl;
                    passed++;
                } else {
                    std::cout << " ✗ НЕ ПРОЙДЕН" << std::endl;
                    std::cout << "   Подробнее: для входа \"" << input << "\" ожидалось " 
                              << expected << ", но получено " << actual << std::endl;
                }
            } else {
                std::cout << " ✗ ОШИБКА ВЫПОЛНЕНИЯ" << std::endl;
            }
        }
        
        std::cout << "=====================================================================\n";
        std::cout << "Результат: " << passed << "/" << total << " тестов пройдено\n";
        
        if (passed == total) {
            std::cout << "✓ Все тесты пройдены успешно! Решение корректно." << std::endl;
        } else {
            std::cout << "✗ Некоторые тесты не пройдены" << std::endl;
        }
    }
    
    // Дополнительная функция для проверки алгоритма напрямую
    void verifyAlgorithm() {
        std::cout << "\nПроверка алгоритма напрямую:\n";
        std::cout << "-----------------------------\n";
        
        // Тестовые случаи для прямой проверки
        struct TestCase {
            std::vector<int> coins;
            int S;
            int expected;
        };
        
        std::vector<TestCase> directTests = {
            {{1, 2, 3}, 4, 4},
            {{1, 2}, 5, 3},
            {{2, 5, 3, 6}, 10, 5},
            {{3}, 5, 0},
            {{3}, 6, 1}
        };
        
        for (size_t i = 0; i < directTests.size(); i++) {
            int result = count_ways_direct(directTests[i].coins, directTests[i].S);
            std::cout << "Прямая проверка " << (i + 1) << ": ";
            std::cout << "coins = [";
            for (size_t j = 0; j < directTests[i].coins.size(); j++) {
                std::cout << directTests[i].coins[j];
                if (j < directTests[i].coins.size() - 1) std::cout << ", ";
            }
            std::cout << "], S = " << directTests[i].S;
            std::cout << " -> " << result;
            if (result == directTests[i].expected) {
                std::cout << " ✓" << std::endl;
            } else {
                std::cout << " ✗ (ожидалось " << directTests[i].expected << ")" << std::endl;
            }
        }
    }
    
private:
    // Функция для прямой проверки (такая же как в main.cpp)
    int count_ways_direct(const std::vector<int>& coins, int S) {
        std::vector<int> dp(S + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int sum = coin; sum <= S; ++sum) {
                dp[sum] += dp[sum - coin];
            }
        }
        return dp[S];
    }
};

int main() {
    system(CLEAR_SCREEN);
    
    Tester tester;
    
    // Компилируем main.cpp
    if (!tester.compile("main.cpp", "main")) {
        std::cerr << "Ошибка компиляции main.cpp!" << std::endl;
        return 1;
    }
    
    std::cout << "Компиляция успешна!\n" << std::endl;
    
    // Запускаем тесты
    tester.runTests();
    
    // Дополнительная проверка алгоритма
    tester.verifyAlgorithm();
    
    return 0;
}