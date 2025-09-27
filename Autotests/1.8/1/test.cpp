#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Timestamp {
    int h, m, s;

    Timestamp(int h_, int m_, int s_) : h(h_), m(m_), s(s_) {}

    static Timestamp from_string(const string& str) {
        int hh = stoi(str.substr(0, 2));
        int mm = stoi(str.substr(3, 2));
        int ss = stoi(str.substr(6, 2));
        return Timestamp(hh, mm, ss);
    }

    int to_seconds() const {
        return h * 3600 + m * 60 + s;
    }

    static Timestamp from_seconds(int total_seconds) {
        total_seconds %= 86400;
        if (total_seconds < 0) total_seconds += 86400;
        int hh = total_seconds / 3600;
        total_seconds %= 3600;
        int mm = total_seconds / 60;
        int ss = total_seconds % 60;
        return Timestamp(hh, mm, ss);
    }

    string to_string() const {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", h, m, s);
        return string(buffer);
    }
};

// Функция, которую мы тестируем (скопирована из main.cpp)
Timestamp calculate_correct_time(const string& A_str, const string& B_str, const string& C_str) {
    Timestamp A = Timestamp::from_string(A_str);
    Timestamp B = Timestamp::from_string(B_str);
    Timestamp C = Timestamp::from_string(C_str);

    const int SECS_IN_DAY = 86400;

    int A_sec = A.to_seconds();
    int B_sec = B.to_seconds();
    int C_sec = C.to_seconds();

    int round_trip = (2 * B_sec + (C_sec - A_sec + SECS_IN_DAY) % SECS_IN_DAY);
    int tm_sec = round_trip / 2 + (round_trip % 2 >= 1 ? 1 : 0);

    return Timestamp::from_seconds(tm_sec);
}

bool run_tests() {
    struct TestCase {
        string A, B, C;
        string expected;
    };

    TestCase tests[] = {
        // Пример из условия
        {"15:01:00", "18:09:45", "15:01:40", "18:10:05"},
        
        // Тест 1: Задержка нулевая (A == C)
        {"12:00:00", "12:00:00", "12:00:00", "12:00:00"},
        
        // Тест 2: Задержка небольшая, округление вниз
        {"10:00:00", "10:00:05", "10:00:09", "10:00:07"},
        
        // Тест 3: Задержка небольшая, округление вверх
        {"10:00:00", "10:00:05", "10:00:10", "10:00:08"},
        
        // Тест 4: Переход через полночь (B > A, C < A)
        {"23:59:00", "00:00:00", "00:00:59", "00:00:29"},
        
        // Тест 5: Большая задержка, но менее 24 часов
        {"00:00:00", "12:00:00", "23:59:59", "17:59:59"},
        
        // Тест 6: Точное совпадение A и C, но B отличается
        {"12:00:00", "13:00:00", "12:00:00", "13:00:00"},
        
        // Тест 7: Отрицательная разница (C < A), корректировка модулем
        {"20:00:00", "20:00:10", "19:59:50", "20:00:00"},
        
        // Тест 8: Еще один тест с округлением
        {"10:00:00", "10:00:00", "10:00:01", "10:00:00"},
        
        // Тест 9: Почти полные сутки разницы
        {"00:00:00", "23:59:59", "23:59:59", "23:59:59"}
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        const TestCase& tc = tests[i];
        Timestamp result = calculate_correct_time(tc.A, tc.B, tc.C);
        if (result.to_string() != tc.expected) {
            cerr << "Test " << (i + 1) << " FAILED\n";
            cerr << "Input: A=" << tc.A << " B=" << tc.B << " C=" << tc.C << "\n";
            cerr << "Expected: " << tc.expected << "\n";
            cerr << "Got: " << result.to_string() << "\n";
            return false;
        }
    }

    return true;
}

int main() {
    if (run_tests()) {
        return 0; // Успех
    } else {
        return 1; // Ошибка
    }
}