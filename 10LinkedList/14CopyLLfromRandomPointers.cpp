#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* random;

    public:
    Node(int data, Node* next, Node* random) {
        this->data = data;
        this->next = next;
        this->random=random;
    }
    
    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->random=nullptr;
    }
};
void Traversal(Node* head) {
    Node* mover = head;

    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }cout << endl;
}

Node* cloneLL(Node*head) {
    unordered_map<Node* ,Node*> mp;
    Node* temp=head;

    while(temp) {
        mp[temp]=new Node(temp->data);
        temp=temp->next;
    }
    // nodes are created into mp

    // links
    temp=head;
    while(temp) {
        // next pointer
        mp[temp]->next = temp->next ? mp[temp->next] : nullptr;
        // random
        mp[temp]->random = temp->random ? mp[temp->random] : nullptr;
        temp=temp->next;
    }
    return mp[head];
}

Node* cloneLL_Optimised(Node* head) {
    // create inbetween nodes
    Node* temp=head;
    while(temp) {
        Node* newNode = new Node(temp->data, temp->next, nullptr);
        temp->next=newNode;
        temp=newNode->next;
    }

    // connect random pointers
    temp=head;
    while(temp) {
        temp->next->random = temp->random ? temp->random->next : nullptr;
        temp=temp->next->next;
    }

    // connect next / separATE  the copied list
    temp=head;
    Node* dummy = new Node(-1);
    Node* res=dummy;
    while(temp) {
        res->next=temp->next;
        res=res->next;
        temp->next=res->next;
        temp=temp->next;
    }
    return dummy->next;
}

int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    Traversal(head);

    // Clone the linked list
    Node* clonedList = cloneLL_Optimised(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    Traversal(clonedList);
}