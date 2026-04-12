#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int x) {
        data = x;
        next=NULL;
        prev=NULL;
    }

    public:
    Node(int x, Node* n, Node* p) {
        data = x;
        next=n;
        prev=p;
    }
};
Node* ArrayToDLL(vector<int> nums) {
    Node* head = new Node(nums[0]);
    Node* temp = head;

    for(int i=1; i<nums.size(); i++) {
        Node* newNode = new Node(nums[i], nullptr, temp);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}
void traversal(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " ";
        temp=temp->next;
    }cout << endl;
}
void removeDup(Node* &head) {
    Node* temp=head;
    Node* newTemp=head;
    while(newTemp) {
        while(newTemp->next && newTemp->data == newTemp->next->data) {
            newTemp=newTemp->next;
        }
        // fix links
        temp->next=newTemp->next;
        if(newTemp->next) { // check last node
            newTemp->next->prev=temp;
        }
        temp=newTemp->next;
        newTemp=temp;
    }
    return;
}

int main() {
    vector<int> nums = {1,1,3,3,4,5};
    Node* head = ArrayToDLL(nums);
    traversal(head);
    removeDup(head);
    traversal(head);
}