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
    if (system("g++ -std=c++11 -w main.cpp -o main.exe") != 0)
        return false;
    system("main.exe < input.txt > output.txt");
#else
    if (system("g++ -std=c++11 -w main.cpp -o main.out") != 0)
        return false;
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
    int total = 1;

    string input =
        "3 2\n"
        "1 2 3\n";

    string expected =
        "Permutations:\n"
        "1 2 3 \n"
        "1 3 2 \n"
        "2 1 3 \n"
        "2 3 1 \n"
        "3 1 2 \n"
        "3 2 1 \n"
        "Arrangements:\n"
        "1 2 \n"
        "1 3 \n"
        "2 1 \n"
        "2 3 \n"
        "3 1 \n"
        "3 2 \n"
        "Combinations:\n"
        "1 2 \n"
        "1 3 \n"
        "2 3 \n";

    if (run_test(input, expected)) {
        cout << "Test passed\n";
        passed++;
    } else {
        cout << "Test failed\n";
    }

    cout << "Passed " << passed << " out of " << total << " tests\n";
    return 0;
}
