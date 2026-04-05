#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
    
    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
}
void Traversal(Node* head) {
    Node* mover = head;

    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }cout << endl;
}
Node* intersection_BF(Node* head1, Node* head2) {
    unordered_map<Node*, int>mp;

    // traverse 1 and cross check from next
    Node* temp=head1;
    while(temp) {
        mp[temp]++;
        temp=temp->next;
    }

    temp=head2;
    while(temp) {
        if(mp.find(temp)!=mp.end()) {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}


int main() {
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    Node* head1 = head;
    head = head->next->next->next;
    
    Node* headSec = NULL;
    insertNode(headSec, 3);
    Node* head2 = headSec;
    headSec->next = head;

    Traversal(head);
    Traversal(headSec);
    cout << "Intersection Node: " << intersection_BF(head1,head2)->data << endl;
}