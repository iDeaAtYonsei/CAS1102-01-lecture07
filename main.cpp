#include <iostream>


// TODO: Define a struct named "Node".
// The struct should include a single character ch followed by a pointer, which will indicate the next Node.
// Think of it as one link in a chain of characters.
struct Node {
    char ch;      // single character
    Node* next;   // pointer to the next Node
};


// TODO: Implement the makeList function.
// It should start with empty head and tail pointers.
// Then, go through the given string to create and connect each Node in order.
void makeList(const char* s, Node*& head, Node*& tail) {
    head = nullptr;
    tail = nullptr;

    for (int i = 0; s[i] != '\0'; ++i) {
        Node* newNode = new Node{s[i], nullptr};  // create a new node

        if (head == nullptr) {  // first node
            head = tail = newNode;
        } else {                // append to tail
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
    makeList("MyName", nameHead, nameTail); // You can freely change the input parameter as your name.


    // TODO: Connect the two linked lists so that printing them together
    // printList function should display "Hello {yourName}" in one line.
    if (helloTail != nullptr) {
        helloTail->next = nameHead; // connect lists
    }


    printList(helloHead);
    
    Node* cur = helloHead;
    while (cur != nullptr) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }

    return 0;
}
