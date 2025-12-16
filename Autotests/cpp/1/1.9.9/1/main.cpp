#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) cin >> arr[i];

    int minIndex = 0, maxIndex = 0;

    // Находим индекс первого минимума и первого максимума
    for (int i = 1; i < N; ++i) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    // Меняем местами только если минимум и максимум различны
    if (minIndex != maxIndex) {
        int temp = arr[minIndex];
        arr[minIndex] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    // Выводим массив через пробел
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
