#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int x) {
        data = x;
        next=NULL;
    }

    public:
    Node(int x, Node* n) {
        data = x;
        next=n;
    }
};
Node* ArrayToDLL(vector<int> nums) {
    Node* head = new Node(nums[0]);
    Node* temp = head;

    for(int i=1; i<nums.size(); i++) {
        Node* newNode = new Node(nums[i]);
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
void reverseKgroups(Node*&head, int k) {
    if(!head || k<=1) return;

    Node* temp=head;
    Node* prevNode=nullptr;

    while(temp) {
        Node* kNode = temp;
        int count = 1;
        // find kth node
        while(count < k && kNode) {
            kNode = kNode->next;
            count++;
        }

        // if less than k nodes left
        if(!kNode) break;

        Node* nextNode = kNode->next;
        kNode->next = nullptr;
        // reverse current group
        Node* newHead = reverseLL_Recursive(temp);

        // first group
        if(temp == head) {
            head = newHead;
        } else {
            prevNode->next = newHead;
        }

        // connect tail
        prevNode = temp;
        temp = nextNode;
    }

    // link to remaining
    if(prevNode) prevNode->next = temp;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    Node* head = ArrayToDLL(nums);
    traversal(head);
    reverseKgroups(head,3);
    traversal(head);
    
}