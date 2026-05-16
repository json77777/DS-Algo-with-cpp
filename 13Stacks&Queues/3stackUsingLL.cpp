#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class stackLL {
public:
    Node* top = nullptr;

    // PUSH
    void push(int x) {
        Node* newNode = new Node(x);

        newNode->next = top;
        top = newNode;
    }

    // POP
    int pop() {

        if(top == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        }

        Node* temp = top;
        int ele = top->data;

        top = top->next;

        delete temp;

        return ele;
    }

    // TOP ELEMENT
    int peek() {
        if(top == nullptr) {
            cout << "Stack Empty\n";
            return -1;
        }

        return top->data;
    }

    // EMPTY CHECK
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {

    stackLL st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.pop() << endl;   // 30
    cout << st.peek() << endl;  // 20

    return 0;
}