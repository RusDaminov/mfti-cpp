#include <iostream>
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


    void print() {
        Node* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
};


int main() {
    SinglyLinkedList list;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push_front") {
            int x; cin >> x;
            list.push_front(x);
        } else if (cmd == "push_back") {
            int x; cin >> x;
            list.push_back(x);
        } else if (cmd == "print") {
            list.print();
        }
    }
    return 0;
}
