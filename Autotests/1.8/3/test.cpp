#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int test_cases[] = {0, 1, 5, 10, 15, 20};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        long long result = factorial(n);
        cout << "factorial(" << n << ") = " << result << endl;
    }
    
    return 0;
}