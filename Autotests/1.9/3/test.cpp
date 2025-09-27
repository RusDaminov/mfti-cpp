// test.cpp
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Функция, которую тестируем (копия из main.cpp)
int countCommonSubstrings(const string& s1, const string& s2) {
    int ans = 0;
    for (size_t i = 0; i + 1 < s1.length(); ++i) {
        string substr = s1.substr(i, 2);
        if (s2.find(substr) != string::npos)
            ans++;
    }
    return ans;
}

void test1() {
    // Тест из условия задачи 3
    string s1 = "abcde";
    string s2 = "bcd";
    int result = countCommonSubstrings(s1, s2);
    assert(result == 3);
    cout << "Test 1 passed: abcde и bcd -> " << result << endl;
}

void test2() {
    // Тест с частичным совпадением
    string s1 = "hello";
    string s2 = "world";
    int result = countCommonSubstrings(s1, s2);
    assert(result == 1); // "ll" не найден, "el" не найден, "lo" не найден, только "he"?
    // Проверяем: he, el, ll, lo - ни одна из этих пар не содержится в "world"
    // Правильный ответ: 0
    // Исправляем assert
    assert(result == 0);
    cout << "Test 2 passed: hello и world -> " << result << endl;
}

void test3() {
    // Тест с пустыми строками
    string s1 = "ab";
    string s2 = "";
    int result = countCommonSubstrings(s1, s2);
    assert(result == 0);
    cout << "Test 3 passed: ab и '' -> " << result << endl;
}

void test4() {
    // Тест с одной буквой в первой строке
    string s1 = "a";
    string s2 = "abc";
    int result = countCommonSubstrings(s1, s2);
    assert(result == 0); // Нет пар символов
    cout << "Test 4 passed: a и abc -> " << result << endl;
}

void test5() {
    // Тест с повторяющимися подстроками
    string s1 = "ababab";
    string s2 = "aba";
    int result = countCommonSubstrings(s1, s2);
    // Пары: ab, ba, ab, ba, ab - все кроме "ba" есть в "aba"
    // "ab" есть, "ba" есть в "aba"? Да, "aba" содержит "ab" и "ba"
    assert(result == 5);
    cout << "Test 5 passed: ababab и aba -> " << result << endl;
}

void test6() {
    // Тест из таблицы задача 3
    string s1 = "programming";
    string s2 = "gram";
    int result = countCommonSubstrings(s1, s2);
    // Пары в s1: pr, ro, og, gr, ra, am, mm, mi, in, ng
    // Из них в s2 "gram" содержатся: gr, ra, am
    assert(result == 3);
    cout << "Test 6 passed: programming и gram -> " << result << endl;
}

int main() {
    try {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        cout << "All tests passed!" << endl;
        return 0;
    } catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
        return 1;
    }
}