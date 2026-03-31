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
Node* ArrayToLinkedList(vector<int> nums) {
    Node* head = new Node(nums[0]);
    Node* mover = head;

    for(int i=1; i<nums.size(); i++) {
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void Traversal(Node* head) {
    Node* mover = head;

    while(mover) {
        cout << mover->data << " ";
        mover = mover->next;
    }cout << endl;
}
void AddHead(Node*& head, int x) {
    Node* temp = new Node(x,head);
    head = temp;
}
void InsertLast(Node* head, int x) {
    Node* temp = head;
    while(temp -> next != NULL) {
        temp=temp->next;
    }
    Node* newNode=new Node(x);
    temp->next=newNode;
}
void InsertAtK(Node*& head, int x, int k) {
    if(k==1) {
        head = new Node(x,head);
        return;
    }
    int c=0;
    Node* temp = head;

    while(temp) {
        c++;
        if(c==k-1) {
            Node* newNode = new Node(x);
            newNode->next = temp->next;
            temp->next=newNode;
            return;
        }
        temp = temp->next;
    }
    if(k > c) {
        cout << "Not possible" << endl;
        return;
    }
}
void reverseLL_Iterative(Node*& head) {
    if(!head) {
        cout << "Empty LL" << endl;
        return;
    }
    Node* prev=NULL;
    Node* curr=head;

    while(curr) {
        Node* forward = curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    head=prev;
}
Node* reverseLL_Recursive(Node* head) {
    // base case
    if(!head || !head->next) {
        return head;
    }
    Node* newHead = reverseLL_Recursive(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
}

int main() {
    vector<int> nums = {12,2,3,4,5};
    Node* head = ArrayToLinkedList(nums);
    Traversal(head);   
    AddHead(head, 5);
    Traversal(head); 
    InsertLast(head, 56);
    Traversal(head);
    InsertAtK(head, 56, 3);
    Traversal(head);
    reverseLL_Iterative(head);
    Traversal(head);
    head = reverseLL_Recursive(head);
    Traversal(head);
}