#include <iostream>
#include <cassert>
#include <cmath>

// Функция для вычисления результата (замените на вашу реализацию)
long long solve(long long N, int K) {
    // Временная заглушка - замените на ваше решение
    // Это пример реализации для K = 1 (сумма арифметической прогрессии)
    if (K == 1) {
        // Находим максимальное m такое, что m*(m+1)/2 <= N
        long long left = 1, right = 2 * sqrt(N) + 10;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sum = mid * (mid + 1) / 2;
            if (sum <= N) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    // Для других значений K нужно реализовать соответствующую логику
    return -1; // Заглушка
}

void runTests() {
    // Тест 1: N = 10, K = 2
    std::cout << "Test 1: N = 10, K = 2" << std::endl;
    long long result1 = solve(10, 2);
    std::cout << "Expected: 4, Got: " << result1 << std::endl;
    assert(result1 == 4);
    std::cout << "Test 1 PASSED\n" << std::endl;

    // Тест 2: N = 1, K = 1
    std::cout << "Test 2: N = 1, K = 1" << std::endl;
    long long result2 = solve(1, 1);
    std::cout << "Expected: 1, Got: " << result2 << std::endl;
    assert(result2 == 1);
    std::cout << "Test 2 PASSED\n" << std::endl;

    // Тест 3: N = 1000000000, K = 1
    std::cout << "Test 3: N = 1000000000, K = 1" << std::endl;
    long long result3 = solve(1000000000, 1);
    std::cout << "Expected: 44721, Got: " << result3 << std::endl;
    assert(result3 == 44721);
    std::cout << "Test 3 PASSED\n" << std::endl;

    // Тест 4: N = 2147483647, K = 1
    std::cout << "Test 4: N = 2147483647, K = 1" << std::endl;
    long long result4 = solve(2147483647, 1);
    std::cout << "Expected: 65536, Got: " << result4 << std::endl;
    assert(result4 == 65536);
    std::cout << "Test 4 PASSED\n" << std::endl;

    // Тест 5: Точный подсчёт суммы арифметической прогрессии
    std::cout << "Test 5: N = 46341 * 46342 / 2, K = 1" << std::endl;
    long long N5 = 46341LL * (46341LL + 1) / 2;
    long long result5 = solve(N5, 1);
    std::cout << "Expected: 46341, Got: " << result5 << std::endl;
    assert(result5 == 46341);
    std::cout << "Test 5 PASSED\n" << std::endl;

    std::cout << "All tests PASSED!" << std::endl;
}

int main() {
    try {
        runTests();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}