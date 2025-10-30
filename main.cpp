#include <iostream>


// TODO: Define a struct named "Node".
// The struct should include a single character ch followed by a pointer, which will indicate the next Node.
// Think of it as one link in a chain of characters.
struct Node {
    char ch;      
    Node* next;   
};

// TODO: Implement the makeList function.
// It should start with empty head and tail pointers.
// Then, go through the given string to create and connect each Node in order.
void makeList(const char* s, Node*& head, Node*& tail) {
    head = nullptr;
    tail = nullptr;
    for (int i = 0; s[i] != '\0'; ++i) {
        Node* newNode = new Node;   // 새 노드 동적 생성
        newNode->ch = s[i];         // 현재 문자를 저장
        newNode->next = nullptr;    // 일단 다음 노드는 없음

        if (head == nullptr) {      // 리스트가 비어있다면
            head = newNode;         // 첫 노드로 설정
            tail = newNode;
        } else {                    // 이미 노드가 있다면
            tail->next = newNode;   // 이전 노드와 연결
            tail = newNode;         // tail을 새 노드로 이동
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
        helloTail->next = nameHead; 
    }

    printList(helloHead);

    return 0;
}
