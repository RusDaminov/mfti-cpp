#include <iostream>
#include <string>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::string result;

    if (x2 > x1) {
        result += std::string(x2 - x1, 'E');
    } else {
        result += std::string(x1 - x2, 'W');
    }

    if (y2 > y1) {
        result += std::string(y2 - y1, 'N');
    } else {
        result += std::string(y1 - y2, 'S');
    }

    std::cout << result << std::endl;

    return 0;
}
