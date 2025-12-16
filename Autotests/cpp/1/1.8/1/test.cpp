#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <string>
using namespace std;

int to_seconds(const string& t) {
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    int s = stoi(t.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

string from_seconds(int sec) {
    sec %= 86400;
    if (sec < 0) sec += 86400;

    int h = sec / 3600; sec %= 3600;
    int m = sec / 60;
    int s = sec % 60;

    char buf[20];
    sprintf(buf, "%02d:%02d:%02d", h, m, s);
    return string(buf);
}

/// Верный SNTP ответ
string correct_answer(const string& A, const string& B, const string& C) {
    const int DAY = 86400;

    int a = to_seconds(A);
    int b = to_seconds(B);
    int c = to_seconds(C);

    int trip = (c - a + DAY) % DAY;      // длительность запроса < 24ч
    int server_time = b + trip / 2;

    // округление по правилам математики
    if (trip % 2 == 1) server_time += 1;

    return from_seconds(server_time);
}

string run_program(const string& input) {
    ofstream fin("input.txt");
    fin << input;
    fin.close();

    system("g++ -std=c++11 -w main.cpp -o main.out");
    system("./main.out < input.txt > output.txt");

    ifstream fout("output.txt");
    string out;
    getline(fout, out);
    fout.close();
    return out;
}

void test_case(int id, const string& A, const string& B, const string& C) {
    string input = A + "\n" + B + "\n" + C + "\n";

    string expected = correct_answer(A, B, C);
    string got = run_program(input);

    cout << "Test " << id << ": expected=" << expected << ", got=" << got << "\n";

    assert(got == expected);
}

int main() {
    cout << "Running SNTP tests...\n\n";

    test_case(1, "10:00:00", "10:00:10", "10:00:20");
    test_case(2, "00:00:00", "00:00:01", "00:00:02");
    test_case(3, "23:59:50", "12:00:00", "00:00:10");
    test_case(4, "18:00:00", "20:00:00", "02:00:00");
    test_case(5, "00:00:00", "00:00:00", "00:00:01");
    test_case(6, "13:37:42", "15:20:10", "17:02:38");
    test_case(7, "01:00:00", "02:00:01", "03:00:02");
    test_case(8, "23:10:10", "05:05:05", "23:10:20");
    test_case(9, "12:00:00", "12:00:00", "11:59:59");

    cout << "\nAll tests passed!\n";
    return 0;
}
