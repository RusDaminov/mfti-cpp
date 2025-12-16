#include <iostream>
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


    void print_forward() {
        Node* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    }


    void print_backward() {
        Node* cur = tail;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->prev;
        }
        cout << "\n";
    }
};


int main() {
    DoublyLinkedList list;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "push_front") {
            int x; cin >> x;
            list.push_front(x);
        } else if (cmd == "push_back") {
            int x; cin >> x;
            list.push_back(x);
        } else if (cmd == "remove") {
            int x; cin >> x;
            list.remove(x);
        } else if (cmd == "print_forward") {
            list.print_forward();
        } else if (cmd == "print_backward") {
            list.print_backward();
        }
    }
    return 0;
}
