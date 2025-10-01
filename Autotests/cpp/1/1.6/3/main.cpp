#include <iostream>
int main() {
 int n, m, k, c;
 std::cin >> n >> m >> k >> c;

 int ans = 0;

 for (int i = 0; i < n; ++i) {
 for (int j = 0; j < m; ++j) {
 if ((i + j) % k + 1 == c) {
 ans++;
 }
 }
 }

 std::cout << ans << std::endl;

 return 0;
}