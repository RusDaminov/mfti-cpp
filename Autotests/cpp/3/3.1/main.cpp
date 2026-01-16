#include <iostream>
using namespace std;


// Факториал
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}


// Перестановки: P(n) = n!
long long permutations(int n) {
    return factorial(n);
}


// Размещения: A(n, k) = n! / (n-k)!
long long arrangements(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = n - k + 1; i <= n; ++i) res *= i;
    return res;
}


// Сочетания: C(n, k) = n! / (k! * (n-k)!)
long long combinations(int n, int k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k; // симметрия
    long long numerator = 1, denominator = 1;
    for (int i = 1; i <= k; ++i) {
        numerator *= (n - i + 1);
        denominator *= i;
    }
    return numerator / denominator;
}


int main() {
    int n, k;
    cin >> n >> k;
    cout << "Permutations P(" << n << ") = " << permutations(n) << "\n";
    cout << "Arrangements A(" << n << ", " << k << ") = " << arrangements(n, k) << "\n";
    cout << "Combinations C(" << n << ", " << k << ") = " << combinations(n, k) << "\n";
    return 0;
}
