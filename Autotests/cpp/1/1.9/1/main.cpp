#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> schools(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> schools[i];
        freq[schools[i]]++;
    }

    // Проверяем, возможно ли рассадить
    int max_freq = 0;
    for (auto& p : freq) {
        max_freq = max(max_freq, p.second);
    }
    if (max_freq > (n + 1) / 2) {
        cout << 0 << endl;
        return 0;
    }

    // Находим школу с максимальным количеством участников
    int dominant = -1;
    for (auto& p : freq) {
        if (p.second == max_freq) {
            dominant = p.first;
            break;
        }
    }

    // Формируем список: сначала все из доминирующей школы
    vector<int> arranged;
    for (int i = 0; i < max_freq; ++i) {
        arranged.push_back(dominant);
    }

    // Добавляем остальных (по возрастанию номера школы)
    for (auto& p : freq) {
        if (p.first == dominant) continue;
        for (int i = 0; i < p.second; ++i) {
            arranged.push_back(p.first);
        }
    }

    // Сортируем "хвост" по возрастанию номера школы
    sort(arranged.begin() + max_freq, arranged.end());

    // Раскладываем: сначала на чётные позиции, потом на нечётные
    vector<int> result(n);
    int idx = 0;

    // Чётные позиции (0, 2, 4, ...)
    for (int i = 0; i < n; i += 2) {
        result[i] = arranged[idx++];
    }
    // Нечётные позиции (1, 3, 5, ...)
    for (int i = 1; i < n; i += 2) {
        result[i] = arranged[idx++];
    }

    // Выводим ответ
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i + 1 < n) cout << " ";
    }
    cout << endl;

    return 0;
}