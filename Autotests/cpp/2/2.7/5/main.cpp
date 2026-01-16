#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
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
    shellSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Shell Sort: " << std::fixed << std::setprecision(6) 
              << duration.count() << " seconds" << std::endl;

    return 0;
}
