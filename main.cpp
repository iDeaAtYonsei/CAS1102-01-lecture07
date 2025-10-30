#include <iostream>

struct Node {
    char ch;
    Node* next;
};

void makeList(const char* s, Node*& head, Node*& tail) {
    head = nullptr;
    tail = nullptr;

    for (int i = 0; s[i] != '\0'; i++) {
        Node* newNode = new Node;
        newNode->ch = s[i];
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        std::cout << cur->ch;
        cur = cur->next;
    }
    std::cout << '\n';
}

int main() {
    Node* helloHead = nullptr;
    Node* helloTail = nullptr;
    makeList("Hello ", helloHead, helloTail);

    Node* nameHead = nullptr;
    Node* nameTail = nullptr;
    makeList("Junyoung", nameHead, nameTail);

    helloTail->next = nameHead;

    printList(helloHead);

    return 0;
}
