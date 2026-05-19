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

class queueLL {
public:
    Node* start = nullptr;
    Node* end = nullptr;

    int currSize = 0;

    // PUSH
    void push(int x) {
        Node* newNode = new Node(x);

        if(currSize == 0) {
            start = newNode;
            end = newNode;
        }
        else {
            end->next = newNode;
            end = newNode;
        }

        currSize++;
    }

    // POP
    int pop() {

        if(start == nullptr) {
            cout << "Queue Underflow\n";
            return -1;
        }

        Node* temp = start;
        int el = temp->data;

        start = start->next;

        if(start == nullptr) {
            end = nullptr;
        }

        delete temp;
        currSize--;

        return el;
    }

    // FRONT ELEMENT
    int peek() {
        if(start == nullptr) {
            cout << "Queue Empty\n";
            return -1;
        }

        return start->data;
    }

    // EMPTY CHECK
    bool isEmpty() {
        return start == nullptr;
    }
};

int main() {

    queueLL *q = new queueLL();

    q->push(34);
    q->push(10);
    q->push(7);

    cout << q->peek() << endl;

    cout << q->pop() << endl;
    cout << q->pop() << endl;

    cout << q->peek() << endl;

    return 0;
}