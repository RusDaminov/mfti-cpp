#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

struct SinglyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_front(int x) {
        Node* node = new Node(x);
        node->next = head;
        head = node;
        if (!tail) tail = node;
    }

    void push_back(int x) {
        Node* node = new Node(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void print(ostream& out) {
        Node* cur = head;
        while (cur) {
            out << cur->val << " ";
            cur = cur->next;
        }
        out << "\n";
    }
};

void list_solution(istream& in, ostream& out) {
    SinglyLinkedList list;
    string cmd;
    while (in >> cmd) {
        if (cmd == "push_front") {
            int x; in >> x;
            list.push_front(x);
        } else if (cmd == "push_back") {
            int x; in >> x;
            list.push_back(x);
        } else if (cmd == "print") {
            list.print(out);
        }
    }
}

int main() {
    struct Test { string input, expected; };
    vector<Test> tests = {
        {"push_back 1\npush_front 2\npush_back 3\nprint\n", "2 1 3 \n"},
        {"push_front 5\npush_front 10\nprint\n", "10 5 \n"},
        {"push_back 7\nprint\n", "7 \n"},
        {"push_back 1\npush_back 2\npush_back 3\nprint\n", "1 2 3 \n"}
    };

    int passed = 0;
    for (auto& t : tests) {
        istringstream in(t.input);
        ostringstream out;
        list_solution(in, out);
        string result = out.str();
        if (result == t.expected) {
            ++passed;
        } else {
            cerr << "Failed test!\nInput:\n" << t.input
                 << "Expected: " << t.expected
                 << "Got: " << result << "\n";
        }
    }

    cout << "Passed " << passed << "/" << tests.size() << " tests\n";
}
