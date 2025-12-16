#include <iostream>
#include <string>
#include <vector>
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
        std::vector<std::pair<std::string, std::string>> testCases = {
            {"123", "131"},
            {"1", "2"},
            {"9", "11"},
            {"99", "101"},
            {"808", "818"},
            {"2133", "2222"},
            {"899", "909"},
            {"999", "1001"}
        };
        
        std::cout << "Запуск тестов для задачи 'Следующий палиндром':\n";
        std::cout << "=============================================\n";
        
        int passed = 0;
        int total = testCases.size();
        
        for (size_t i = 0; i < testCases.size(); i++) {
            std::string input = testCases[i].first;
            std::string expected = testCases[i].second;
            std::string actual;
            
            std::cout << "Тест " << (i + 1) << ": Вход = " << input;
            std::cout << ", Ожидается = " << expected;
            
            if (runTest("main", input, actual)) {
                std::cout << ", Получено = " << actual;
                
                if (actual == expected) {
                    std::cout << " ✓ ПРОЙДЕН" << std::endl;
                    passed++;
                } else {
                    std::cout << " ✗ НЕ ПРОЙДЕН" << std::endl;
                }
            } else {
                std::cout << " ✗ ОШИБКА ВЫПОЛНЕНИЯ" << std::endl;
            }
        }
        
        std::cout << "=============================================\n";
        std::cout << "Результат: " << passed << "/" << total << " тестов пройдено\n";
        
        if (passed == total) {
            std::cout << "✓ Все тесты пройдены успешно!" << std::endl;
        } else {
            std::cout << "✗ Некоторые тесты не пройдены" << std::endl;
        }
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
    
    return 0;
}