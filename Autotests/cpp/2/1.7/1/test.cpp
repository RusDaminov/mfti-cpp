#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

int main() {
    const int N = 1000; 
    const int MAX_VAL = 1000;

    std::vector<int> arr(N);
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, MAX_VAL);

    for (int i = 0; i < N; ++i) arr[i] = dist(rng);

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    // Проверка
    if (!std::is_sorted(arr.begin(), arr.end())) {
        std::cerr << "BubbleSort failed!\n";
        return 1;
    }

    std::chrono::duration<double> duration = end - start;
    std::cout << "Bubble Sort passed. Time: " 
              << std::fixed << std::setprecision(6)
              << duration.count() << " seconds" << std::endl;

    return 0;
}
