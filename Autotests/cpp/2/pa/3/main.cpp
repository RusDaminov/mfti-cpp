#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class List {
private:
    Node* head;

    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }

    void split(Node* src, Node** a, Node** b) {
        Node* slow = src;
        Node* fast = src->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *a = src;
        *b = slow->next;
        slow->next = nullptr;
    }

    void mergeSort(Node** h) {
        if (!*h || !(*h)->next) return;

        Node* a;
        Node* b;

        split(*h, &a, &b);
        mergeSort(&a);
        mergeSort(&b);

        *h = merge(a, b);
    }

public:
    List() : head(nullptr) {}

    ~List() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
    }

    void append(int x) {
        if (!head) {
            head = new Node(x);
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(x);
    }

    void sort() {
        mergeSort(&head);
    }

    void print(ofstream& out) {
        for (Node* c = head; c; c = c->next) {
            out << c->val;
            if (c->next) out << " ";
        }
    }
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    List list;
    int x;
    while (in >> x) list.append(x);

    list.sort();
    list.print(out);
    return 0;
}
