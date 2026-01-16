#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;

/* Подключаем main.cpp как библиотеку */
#define main dont_use_main
#include "main.cpp"
#undef main

bool test_case(
    const vector<int>& data,
    int expected_sum,
    bool expect_error,
    int expected_min = 0,
    int expected_max = 0
) {
    SinglyLinkedList list;
    for (int x : data)
        list.append(x);

    try {
        int s = list.sum();
        if (s != expected_sum) return false;

        int mn = list.minimum();
        int mx = list.maximum();

        if (expect_error) return false;
        return mn == expected_min && mx == expected_max;
    }
    catch (...) {
        return expect_error;
    }
}

int main() {
    int passed = 0;
    int total = 5;

    passed += test_case({1, 2, 3}, 6, false, 1, 3);
    passed += test_case({5}, 5, false, 5, 5);
    passed += test_case({}, 0, true);
    passed += test_case({-1, -5, 0, 10}, 4, false, -5, 10);
    passed += test_case({7, 7, 7}, 21, false, 7, 7);

    cout << "Passed " << passed << " / " << total << " tests\n";

    if (passed == total)
        cout << "ALL TESTS PASSED ✅\n";
    else
        cout << "SOME TESTS FAILED ❌\n";

    return 0;
}
