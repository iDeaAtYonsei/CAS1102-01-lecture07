#include <iostream>

struct Node {
    char ch;
    Node* next;
};

// TODO: Define a struct named "Node".
// The struct should include a single character ch followed by a pointer, which will indicate the next Node.
// Think of it as one link in a chain of characters.


// TODO: Implement the makeList function.
// It should start with empty head and tail pointers.
// Then, go through the given string to create and connect each Node in order.
void makeList(const char* s, Node*& head, Node*& tail) {
    head = nullptr;
    tail = nullptr;
    for (const char* p = s; *p != '\0'; ++p) {
        Node* cur = new Node{*p, nullptr};
        if (!head) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
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
    makeList("MyName", nameHead, nameTail); // You can freely change the input parameter as your name.


    // TODO: Connect the two linked lists so that printing them together
    // printList function should display "Hello {yourName}" in one line.
    if (helloTail) {
        helloTail->next = nameHead;
    } else {
        helloHead = nameHead;
    }
    if (nameTail) {
        helloTail = nameTail;
    }

    printList(helloHead);

    return 0;
}
