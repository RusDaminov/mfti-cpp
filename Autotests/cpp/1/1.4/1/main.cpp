#include <iostream>
using namespace std;

int main() {
    int N, K;
    
    cout << "Введите N: ";
    cin >> N;
    
    cout << "Введите K: ";
    cin >> K;

    int M = (N - K + 1) / 2;

    if (M < K) {
        cout << 0 << endl;
    } else {
        cout << M - K << endl;
    }

    return 0;
}
