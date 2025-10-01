#include <iostream>
using namespace std;
int main() {
 long long N, K;
 cout << "Введите N: ";
 cin >> N;
 cout << "Введите K: ";
 cin >> K;
 long long solved = 0;
 int day = 0;
 while (solved < N) {
 solved += K;
 K++;
 day++;
 }
 cout << "Ответ: " << day << endl;
 return 0;
}