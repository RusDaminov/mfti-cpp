#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val < b->val) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

Node* split(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;
    return mid;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* mid = split(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}

string listToString(Node* head) {
    ostringstream out;
    while (head) {
        out << head->val << " ";
        head = head->next;
    }
    return out.str();
}

void list_solution(istream& in, ostream& out) {
    int n; in >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; in >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    head = mergeSort(head);
    out << listToString(head) << "\n";
}

int main() {
    struct Test { string input, expected; };
    vector<Test> tests = {
        {"5\n3 1 4 2 5\n", "1 2 3 4 5 \n"},
        {"3\n10 5 7\n", "5 7 10 \n"},
        {"4\n1 2 3 4\n", "1 2 3 4 \n"},
        {"1\n100\n", "100 \n"},
        {"6\n6 5 4 3 2 1\n", "1 2 3 4 5 6 \n"}
    };

    int passed = 0;
    for (auto& t : tests) {
        istringstream in(t.input);
        ostringstream out;
        list_solution(in, out);
        if (out.str() == t.expected) {
            ++passed;
        } else {
            cerr << "Test failed!\nInput:\n" << t.input
                 << "Expected: " << t.expected
                 << "Got: " << out.str() << "\n";
        }
    }

    cout << "Passed " << passed << "/" << tests.size() << " tests\n";
}
