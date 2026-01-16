#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm> // для std::is_sorted

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int N = 100000; // Размер массива
    const int MAX_VAL = 100000;

    std::vector<int> arr(N);
    std::mt19937 rng(42); // фиксируем генератор для теста
    std::uniform_int_distribution<int> dist(0, MAX_VAL);

    for (int i = 0; i < N; ++i) arr[i] = dist(rng);

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    // Проверка корректности сортировки
    if (!std::is_sorted(arr.begin(), arr.end())) {
        std::cerr << "QuickSort failed!\n";
        return 1;
    }

    std::chrono::duration<double> duration = end - start;
    std::cout << "Quick Sort passed. Time: "
              << std::fixed << std::setprecision(6)
              << duration.count() << " seconds" << std::endl;

    return 0;
}
