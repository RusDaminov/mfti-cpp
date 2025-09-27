#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int find_substring(const string& text, const string& pattern) {
    // Handle edge cases
    if (pattern.empty()) return 0; // Empty pattern matches at start
    if (text.empty()) return -1;   // Empty text can't contain non-empty pattern
    
    size_t text_len = text.length();
    size_t pattern_len = pattern.length();
    
    if (pattern_len > text_len) return -1;
    
    // Simple brute-force substring search
    for (size_t i = 0; i <= text_len - pattern_len; ++i) {
        bool found = true;
        for (size_t j = 0; j < pattern_len; ++j) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return static_cast<int>(i); // Return the starting index
        }
    }
    
    return -1; // Pattern not found
}

void run_tests() {
    struct TestCase {
        string text;
        string pattern;
        int expected;
    };
    
    TestCase tests[] = {
        {"abracadabra", "cada", 4},
        {"hello world", "world", 6},
        {"opænai", "ai", 4},
        {"mississippi", "issip", 4},
        {"abcdef", "gh", -1},
        {"", "abc", -1},           // Empty text
        {"abc", "", 0},            // Empty pattern
        {"abc", "abc", 0},         // Exact match
        {"abc", "abcd", -1}        // Pattern longer than text
    };
    
    // Fix the signedness warning by using size_t
    size_t num_tests = sizeof(tests)/sizeof(tests[0]);
    for (size_t i = 0; i < num_tests; ++i) {
        int result = find_substring(tests[i].text, tests[i].pattern);
        assert(result == tests[i].expected);
        cout << "Test " << i+1 << " passed: text='" << tests[i].text 
             << "', pattern='" << tests[i].pattern 
             << "' -> " << result << endl;
    }
    
    cout << "All tests passed!" << endl;
}

int main() {
    run_tests();
    return 0;
}