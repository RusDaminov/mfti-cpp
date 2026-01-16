#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

bool run_test(const string& input, const string& expected) {
    ofstream fin("input.txt");
    fin << input;
    fin.close();

#ifdef _WIN32
    int compile_status = system("g++ -std=c++11 -w main.cpp -o main.exe");
    if (compile_status != 0) return false;
    system("main.exe < input.txt > output.txt");
#else
    int compile_status = system("g++ -std=c++11 -w main.cpp -o main.out");
    if (compile_status != 0) return false;
    system("./main.out < input.txt > output.txt");
#endif

    ifstream fout("output.txt");
    string output, line;
    while (getline(fout, line)) {
        output += line + "\n";
    }
    fout.close();

    return output == expected;
}

int main() {
    int passed = 0;
    int total = 3;

    if (run_test(
        "5 2\n",
        "Permutations P(5) = 120\n"
        "Arrangements A(5, 2) = 20\n"
        "Combinations C(5, 2) = 10\n"
    )) {
        cout << "Test 1 passed\n";
        passed++;
    } else {
        cout << "Test 1 failed\n";
    }

    if (run_test(
        "6 3\n",
        "Permutations P(6) = 720\n"
        "Arrangements A(6, 3) = 120\n"
        "Combinations C(6, 3) = 20\n"
    )) {
        cout << "Test 2 passed\n";
        passed++;
    } else {
        cout << "Test 2 failed\n";
    }

    if (run_test(
        "4 5\n",
        "Permutations P(4) = 24\n"
        "Arrangements A(4, 5) = 0\n"
        "Combinations C(4, 5) = 0\n"
    )) {
        cout << "Test 3 passed\n";
        passed++;
    } else {
        cout << "Test 3 failed\n";
    }

    cout << "Passed " << passed << " out of " << total << " tests\n";
    return 0;
}
