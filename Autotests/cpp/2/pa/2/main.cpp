#include <iostream>
#include <stdexcept>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void append(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = new Node(val);
    }

    int sum() const {
        int s = 0;
        Node* cur = head;
        while (cur) {
            s += cur->value;
            cur = cur->next;
        }
        return s;
    }

    int minimum() const {
        if (!head)
            throw runtime_error("List is empty");

        int mn = head->value;
        Node* cur = head->next;
        while (cur) {
            if (cur->value < mn)
                mn = cur->value;
            cur = cur->next;
        }
        return mn;
    }

    int maximum() const {
        if (!head)
            throw runtime_error("List is empty");

        int mx = head->value;
        Node* cur = head->next;
        while (cur) {
            if (cur->value > mx)
                mx = cur->value;
            cur = cur->next;
        }
        return mx;
    }
};

/*
main не используется напрямую.
Он нужен, чтобы файл корректно компилировался.
*/
int main() {
    return 0;
}
