#include <iostream>


// TODO: Define a struct named "Node".
// The struct should include a single character ch followed by a pointer, which will indicate the next Node.
// Think of it as one link in a chain of characters.
struct Node
{
    char ch;
    Node* next;
};



// TODO: Implement the makeList function.
// It should start with empty head and tail pointers.
// Then, go through the given string to create and connect each Node in order.
void makeList(const char* s, Node*& head, Node*& tail) {
    // go through the given string
    for (int i = 0; s[i] != '\0'; ++i) {
        Node* newNode = new Node{s[i], nullptr};

        // List is empty; the first Node
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else { // List is not empty; need to connect to the next Node
            tail->next = newNode; // Connect to nect Node
            tail = newNode;       // Update the pointer
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
    helloTail -> next = nameHead; // Connect the tail of "Hello" and head of "MyName"


    printList(helloHead);

    return 0;
}
