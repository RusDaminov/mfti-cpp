#include <iostream>
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


void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}


int main() {
    int n; cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    head = mergeSort(head);
    printList(head);
    return 0;
}
