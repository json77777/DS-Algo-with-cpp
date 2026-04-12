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
void deleteOccurances(Node*& head, int key) {
    if(!head) return;
    Node* temp=head;

    while(head && head->data == key) {
        Node* delHead=head;
        head=head->next;
        temp=head; // update the head here if deleted. !!
        if(head) head->prev=nullptr;
        delete delHead;
    }

    while(temp) {
        if(temp->data == key) {
            Node* delNode=temp;
            
            if(temp->next) 
                temp->next->prev=temp->prev;

            temp->prev->next=temp->next;
            temp=temp->next;

            delete delNode;

        } else {
            temp=temp->next;
        }
    }
}

int main() {
    vector<int> nums = {10,4,10,6,10};
    Node* head = ArrayToDLL(nums);
    traversal(head);
    deleteOccurances(head,10);
    traversal(head);

}