#include <iostream>
#include <string>
#include <algorithm>

// Функция для проверки, является ли число палиндромом
bool isPalindrome(const std::string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Функция для нахождения следующего палиндрома
std::string nextPalindrome(const std::string& n) {
    std::string num = n;
    int len = num.length();
    
    // Увеличиваем число на 1
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] != '9') {
            num[i]++;
            break;
        } else {
            num[i] = '0';
            if (i == 0) {
                num = "1" + num;
                len++;
            }
        }
    }
    
    // Находим ближайший палиндром
    while (true) {
        // Создаем зеркальную копию левой половины
        std::string candidate = num;
        for (int i = 0; i < len / 2; i++) {
            candidate[len - 1 - i] = candidate[i];
        }
        
        // Если зеркальная версия >= исходного числа, это наш ответ
        if (candidate >= num) {
            return candidate;
        }
        
        // Иначе увеличиваем среднюю цифру и пробуем снова
        int mid = (len - 1) / 2;
        for (int i = mid; i >= 0; i--) {
            if (candidate[i] != '9') {
                candidate[i]++;
                // Обновляем симметричную позицию
                if (i != len - 1 - i) {
                    candidate[len - 1 - i]++;
                }
                break;
            } else {
                candidate[i] = '0';
                candidate[len - 1 - i] = '0';
            }
        }
        num = candidate;
    }
}

int main() {
    std::string n;
    std::cin >> n;
    
    std::string result = nextPalindrome(n);
    std::cout << result << std::endl;
    
    return 0;
}