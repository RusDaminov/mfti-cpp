#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

void countingSort(std::vector<int>& arr, int max_val) {
    int n = arr.size();
    std::vector<int> count(max_val + 1, 0);
    for (int i = 0; i < n; ++i) count[arr[i]]++;
    int index = 0;
    for (int i = 0; i <= max_val; ++i) {
        while (count[i]--) arr[index++] = i;
    }
}

int main() {
    const int N = 100000;
    const int MAX_VAL = 100000;
    std::vector<int> arr(N);
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, MAX_VAL);
    for (int i = 0; i < N; ++i) arr[i] = dist(rng);

    auto start = std::chrono::high_resolution_clock::now();
    countingSort(arr, MAX_VAL);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Counting Sort: " << std::fixed << std::setprecision(6) 
              << duration.count() << " seconds" << std::endl;

    return 0;
}
