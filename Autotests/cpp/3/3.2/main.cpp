#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Перестановки всех элементов массива
void printPermutations(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    do {
        for (int x : arr) cout << x << " ";
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));
}


// Размещения: все упорядоченные варианты длины k из n элементов
void printArrangements(const vector<int>& arr, int k, vector<int>& cur, vector<bool>& used) {
    if ((int)cur.size() == k) {
        for (int x : cur) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < (int)arr.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            cur.push_back(arr[i]);
            printArrangements(arr, k, cur, used);
            cur.pop_back();
            used[i] = false;
        }
    }
}


// Сочетания: все варианты без учета порядка длины k из n элементов
void printCombinations(const vector<int>& arr, int k, int start, vector<int>& cur) {
    if ((int)cur.size() == k) {
        for (int x : cur) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = start; i < (int)arr.size(); ++i) {
        cur.push_back(arr[i]);
        printCombinations(arr, k, i + 1, cur);
        cur.pop_back();
    }
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;


    cout << "Permutations:\n";
    printPermutations(arr);


    cout << "Arrangements:\n";
    vector<int> cur;
    vector<bool> used(n, false);
    printArrangements(arr, k, cur, used);


    cout << "Combinations:\n";
    printCombinations(arr, k, 0, cur);


    return 0;
}
