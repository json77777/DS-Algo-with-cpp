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

void Add1(Node* &head) {

    if(!head) {
        head=new Node(1,nullptr);
        return;
    }

    // reverse LL
    head=reverseLL_Recursive(head);

    int c=1; // carry

    Node* temp=head;
    while(temp) {
        if(temp->data + c > 9) {
            c=1;
            temp->data=0;
        }
        else if(temp->data + c < 9) {
            temp->data=temp->data+c;
            c=0;
            break;
        }
        temp=temp->next;
    }

    head=reverseLL_Recursive(head);

    if(c) {
        Node* newNode = new Node(c,head);
        head=newNode;
    }
    else {
        return;
    }

}


int helper(Node* &head) {
    if(head == nullptr) {
        return 1;
    }
    int c = helper(head->next);
    head->data=head->data+c;
    if(head->data > 9) {
        head->data=0;
        return 1;
    }
    else return 0;
}
void Add_Recurr(Node*&head) {
    int carry = helper(head);
    if(carry) {
        Node* newNode = new Node(1,head);
        head=newNode;
    }
    return;
}


int main() {
    vector<int> nums = {1,3,0};
    Node* head = ArrayToLinkedList(nums);
    Traversal(head);   
    Add1(head); // O(2n)
    Traversal(head);
    Add_Recurr(head); // tc->O(n) + sc->O(n)
    Traversal(head); 
}