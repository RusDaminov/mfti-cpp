#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <algorithm> // для std::is_sorted

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int N = 100000; // Размер массива
    const int MAX_VAL = 100000;

    std::vector<int> arr(N);
    std::mt19937 rng(42); // фиксированный генератор для повторяемости
    std::uniform_int_distribution<int> dist(0, MAX_VAL);

    for (int i = 0; i < N; ++i) arr[i] = dist(rng);

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    // Проверка корректности сортировки
    if (!std::is_sorted(arr.begin(), arr.end())) {
        std::cerr << "MergeSort failed!\n";
        return 1;
    }

    std::chrono::duration<double> duration = end - start;
    std::cout << "Merge Sort passed. Time: " 
              << std::fixed << std::setprecision(6) 
              << duration.count() << " seconds" << std::endl;

    return 0;
}
