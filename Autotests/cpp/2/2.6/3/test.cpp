#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

struct TestCase {
    string input;
    vector<set<string>> expected_groups;
};

set<set<string>> parse_output(const string &text) {
    istringstream iss(text);
    string line;
    set<set<string>> groups;
    while (getline(iss, line)) {
        istringstream ls(line);
        set<string> group;
        string word;
        while (ls >> word) group.insert(word);
        if (!group.empty()) groups.insert(group);
    }
    return groups;
}

int main() {
    vector<TestCase> tests = {
        {"5\neat\ntea\ntan\nate\nnat\n", {{"eat", "tea", "ate"}, {"tan", "nat"}}},
        {"3\nabc\nbac\ncab\n", {{"abc", "bac", "cab"}}},
        {"4\ndog\ngod\ncat\nact\n", {{"dog", "god"}, {"cat", "act"}}},
        {"2\none\ntwo\n", {{"one"}, {"two"}}},
        {"6\na\nab\nba\nb\naa\nbb\n", {{"a"}, {"ab", "ba"}, {"b"}, {"aa"}, {"bb"}}}
    };

    int passed = 0, total = tests.size();

    if (system("g++ -std=c++11 -w main.cpp -o main") != 0) {
        cerr << "Ошибка компиляции main.cpp" << endl;
        return 1;
    }

    for (size_t i = 0; i < tests.size(); ++i) {
        ofstream input("input.txt");
        input << tests[i].input;
        input.close();

        system("./main < input.txt > output.txt");

        ifstream output("output.txt");
        string result((istreambuf_iterator<char>(output)), istreambuf_iterator<char>());
        output.close();

        auto out_groups = parse_output(result);
        set<set<string>> expected(tests[i].expected_groups.begin(), tests[i].expected_groups.end());

        if (out_groups == expected) {
            cout << "Тест " << i + 1 << " пройден ✅\n";
            passed++;
        } else {
            cout << "Тест " << i + 1 << " провален ❌\n";
            cout << "Вывод программы:\n" << result << endl;
        }
    }

    cout << "\nРезультат: " << passed << "/" << total << " тестов успешно.\n";
    return 0;
}
