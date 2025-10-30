#include <iostream>

// Define the Node struct
struct Node {
    char ch;       // single character
    Node* next;    // pointer to next node
    Node(char c) : ch(c), next(nullptr) {} // constructor
};

// Implement the makeList function
void makeList(const char* s, Node*& head, Node*& tail) {
    head = nullptr;
    tail = nullptr;

    for (int i = 0; s[i] != '\0'; ++i) {
        Node* newNode = new Node(s[i]);
        if (head == nullptr) {
            head = newNode;   // first node
            tail = newNode;
        } else {
            tail->next = newNode; // connect to previous node
            tail = newNode;       // move tail to new node
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
    makeList("Geon Yun", nameHead, nameTail); // your name here

    // Connect the two linked lists
    helloTail->next = nameHead;

    // Print "Hello Geon Yun"
    printList(helloHead);

    return 0;
}
