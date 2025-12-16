#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    void push_front(int x) {
        Node* node = new Node(x);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
    }

    void push_back(int x) {
        Node* node = new Node(x);
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
    }

    void remove(int x) {
        Node* cur = head;
        while (cur) {
            if (cur->val == x) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                else tail = cur->prev;
                delete cur;
                return;
            }
            cur = cur->next;
        }
    }

    void print_forward(ostream& out) {
        Node* cur = head;
        while (cur) {
            out << cur->val << " ";
            cur = cur->next;
        }
        out << "\n";
    }

    void print_backward(ostream& out) {
        Node* cur = tail;
        while (cur) {
            out << cur->val << " ";
            cur = cur->prev;
        }
        out << "\n";
    }
};

void list_solution(istream& in, ostream& out) {
    DoublyLinkedList list;
    string cmd;
    while (in >> cmd) {
        if (cmd == "push_front") {
            int x; in >> x;
            list.push_front(x);
        } else if (cmd == "push_back") {
            int x; in >> x;
            list.push_back(x);
        } else if (cmd == "remove") {
            int x; in >> x;
            list.remove(x);
        } else if (cmd == "print_forward") {
            list.print_forward(out);
        } else if (cmd == "print_backward") {
            list.print_backward(out);
        }
    }
}

int main() {
    struct Test { string input, expected; };
    vector<Test> tests = {
        {"push_back 1\npush_back 2\npush_back 3\nprint_forward\nprint_backward\n",
         "1 2 3 \n3 2 1 \n"},
        {"push_front 5\npush_front 10\nprint_forward\n", "10 5 \n"},
        {"push_back 7\nremove 5\nprint_forward\n", "7 \n"},
        {"push_back 1\npush_back 2\nremove 1\nprint_forward\n", "2 \n"}
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
