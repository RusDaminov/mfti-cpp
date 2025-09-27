#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Timestamp {
    int h, m, s;

    Timestamp(int h_, int m_, int s_) : h(h_), m(m_), s(s_) {}

    // Парсим из формата "чч:мм:сс"
    static Timestamp from_string(const string& str) {
        int hh = stoi(str.substr(0, 2));
        int mm = stoi(str.substr(3, 2));
        int ss = stoi(str.substr(6, 2));
        return Timestamp(hh, mm, ss);
    }

    // Переводим во секунды с начала суток
    int to_seconds() const {
        return h * 3600 + m * 60 + s;
    }

    // Создаём Timestamp из секунд (по модулю 24 часа)
    static Timestamp from_seconds(int total_seconds) {
        total_seconds %= 86400; // секунд в сутках
        if (total_seconds < 0) total_seconds += 86400;
        int hh = total_seconds / 3600;
        total_seconds %= 3600;
        int mm = total_seconds / 60;
        int ss = total_seconds % 60;
        return Timestamp(hh, mm, ss);
    }

    // Вывод в формате "чч:мм:сс"
    string to_string() const {
        stringstream ss;
        ss << setw(2) << setfill('0') << h << ":"
           << setw(2) << setfill('0') << m << ":"
           << setw(2) << setfill('0') << s;
        return ss.str();
    }
};

int main() {
    string A_str, B_str, C_str;
    getline(cin, A_str);
    getline(cin, B_str);
    getline(cin, C_str);

    Timestamp A = Timestamp::from_string(A_str);
    Timestamp B = Timestamp::from_string(B_str);
    Timestamp C = Timestamp::from_string(C_str);

    const int SECS_IN_DAY = 86400;

    int A_sec = A.to_seconds();
    int B_sec = B.to_seconds();
    int C_sec = C.to_seconds();

    // Считаем общее время в пути (по модулю 24 часа)
    int round_trip = (2 * B_sec + (C_sec - A_sec + SECS_IN_DAY) % SECS_IN_DAY);

    // Делим на 2 с округлением: если остаток >= 1, округляем вверх
    int tm_sec = round_trip / 2 + (round_trip % 2 >= 1 ? 1 : 0);

    // Конвертируем обратно в Timestamp
    Timestamp result = Timestamp::from_seconds(tm_sec);

    cout << result.to_string() << "\n";

    return 0;
}
