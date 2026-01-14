// #include <iostream>
// #include <string>
// using namespace std;

// string python_slice(const string& s, int start, int end, int step) {
//     int n = s.size();
//     // Обработка отрицательных индексов
//     if (start < 0) start += n;
//     if (end < 0) end += n;
//     // Ограничения по границам
//     if (step > 0) {
//         if (start < 0) start = 0;
//         if (end > n) end = n;
//     } else {
//         if (start >= n) start = n - 1;
//         if (end < -1) end = -1;
//     }
//     string res;
//     if (step > 0) {
//         for (int i = start; i < end; i += step)
//             if (i >= 0 && i < n) res += s[i];
//     } else if (step < 0) {
//         for (int i = start; i > end; i += step)
//             if (i >= 0 && i < n) res += s[i];
//     }
//     return res;
// }

// int main() {
//     string s;
//     int start, end, step;
//     cin >> s >> start >> end >> step;
//     cout << python_slice(s, start, end, step) << endl;
//     return 0;
// }

#include <iostream>
#include <string>
#include <algorithm>

std::string python_slice(const std::string& S, int start, int end, int step) {
    int length = S.length();
    
    // Если step == 0, возвращаем пустую строку (как в Python)
    if (step == 0) {
        return "";
    }
    
    // Определяем начальный индекс
    if (start < 0) start += length;
    if (start < 0) start = (step > 0) ? 0 : -1;
    else if (start >= length) start = (step > 0) ? length : length - 1;
    
    // Определяем конечный индекс
    if (end < 0) end += length;
    if (end < 0) end = (step > 0) ? 0 : -1;
    else if (end >= length) end = (step > 0) ? length : -1;
    
    // Формируем результат
    std::string result;
    
    if (step > 0) {
        // Прямой порядок
        start = std::max(0, start);
        end = std::min(length, end);
        if (start >= end) return "";
        
        for (int i = start; i < end; i += step) {
            result.push_back(S[i]);
        }
    } else {
        // Обратный порядок (step < 0)
        if (start < 0) start = length - 1;
        else if (start >= length) start = length - 1;
        
        if (end < 0) end = -1;
        else if (end >= length) end = -1;
        
        if (start <= end) return "";
        
        for (int i = start; i > end; i += step) {
            result.push_back(S[i]);
        }
    }
    
    return result;
}

int main() {
    std::string S;
    int start, end, step;
    
    std::cin >> S >> start >> end >> step;
    std::cout << python_slice(S, start, end, step) << std::endl;
    
    return 0;
}