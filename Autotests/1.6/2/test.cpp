#include <iostream>
using namespace std;

int main() {
    int test_cases[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int expected_n3[] = {0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 5};
    int expected_n4[] = {0, 0, 0, 0, 1, 1, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0};

    for (int i = 0; i < 16; i++) {
        int m = test_cases[i];
        int n4 = m % 3;
        int n3 = (m - 4 * n4) / 3;

        if (n3 >= 0) {
            if (n3 == expected_n3[i] && n4 == expected_n4[i]) {
                cout << "Test " << m << ": PASS" << endl;
            } else {
                cout << "Test " << m << ": FAIL (expected n3=" << expected_n3[i] 
                     << " n4=" << expected_n4[i] << ", got n3=" << n3 
                     << " n4=" << n4 << ")" << endl;
            }
        } else {
            if (expected_n3[i] == 0 && expected_n4[i] == 0) {
                cout << "Test " << m << ": PASS" << endl;
            } else {
                cout << "Test " << m << ": FAIL (expected n3=" << expected_n3[i] 
                     << " n4=" << expected_n4[i] << ", got 0,0)" << endl;
            }
        }
    }

    return 0;
}