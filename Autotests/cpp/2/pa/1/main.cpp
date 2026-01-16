#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Конструктор
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    // Деструктор
    ~SinglyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    // Добавление в конец
    void append(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Печать списка
    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->value;
            if (cur->next) cout << " ";
            cur = cur->next;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int x;

    // Читаем числа до конца ввода
    while (cin >> x) {
        list.append(x);
    }

    list.print();
    return 0;
}
