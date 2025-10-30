#include <iostream>


// TODO: Define a struct named "Node".
// The struct should include a single character ch followed by a pointer, which will indicate the next Node.
// Think of it as one link in a chain of characters.
struct Node{
    char ch;
    Node * next; 

    // 생성자 추가: 문자와 다음 포인터를 한 번에 설정
    Node(char c, Node* n = nullptr) : ch(c), next(n) {}
};

// TODO: Implement the makeList function.
// It should start with empty head and tail pointers.
// Then, go through the given string to create and connect each Node in order.
void makeList(const char* s, Node*& head, Node*& tail) {
     head = nullptr;
     tail = nullptr;

     if (s == nullptr) return;

     // C-string을 '\0'이 나올 때까지 순회
     for (const char* p = s; *p != '\0'; ++p) {
         Node* newNode = new Node(*p, nullptr);  // 새 노드 생성
         if (head == nullptr) {
             head = newNode;
             tail = newNode;
         } else {
             tail->next = newNode;   // 이전 꼬리 노드에 이어붙이기
             tail = newNode;         // tail 갱신
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
    makeList("KIM KEON", nameHead, nameTail); // You can freely change the input parameter as your name.


    // TODO: Connect the two linked lists so that printing them together
    // printList function should display "Hello {yourName}" in one line.
    helloTail->next = nameHead;

    printList(helloHead);

    return 0;
}
