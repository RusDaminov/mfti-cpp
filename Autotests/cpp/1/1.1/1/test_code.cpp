#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkConstraints(const string &num) {
    if (num.size() != 5) return false;

    int lessThan5 = 0, oddCount = 0;
    for (char c : num) {
        int d = c - '0';
        if (d < 5) lessThan5++;
        if (d % 2 == 1) oddCount++;
    }

    return (lessThan5 >= 3 && oddCount >= 3);
}

int main() {
    string studentAnswer;
    cin >> studentAnswer;

    string correctAnswer = "99443";

    if (!checkConstraints(studentAnswer)) {
        cout << "❌ Ответ не удовлетворяет условиям задачи" << endl;
    } else if (studentAnswer != correctAnswer) {
        cout << "❌ Ответ неверный. Ожидалось: " << correctAnswer 
             << ", получено: " << studentAnswer << endl;
    } else {
        cout << "✅ Ответ правильный!" << endl;
    }

    return 0;
}