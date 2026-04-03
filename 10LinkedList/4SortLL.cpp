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
Node* middleNode(Node* head) { // O(n)
    Node* slow = head;
    Node* fast = head->next; // want first mid
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* Merge(Node* firstHead, Node* secondHead) {
    if(!firstHead) return secondHead;
    if(!secondHead) return firstHead;

    Node* head = nullptr;
    Node* temp = nullptr;

    // initialize head
    if(firstHead->data <= secondHead->data) {
        head = firstHead;
        temp = head;
        firstHead = firstHead->next;
    } else {
        head = secondHead;
        temp = head;
        secondHead = secondHead->next;
    }

    while(firstHead && secondHead) {
        if(firstHead->data <= secondHead->data) {
            temp->next = firstHead;
            temp = temp->next;
            firstHead = firstHead->next;
        } else {
            temp->next = secondHead;
            temp = temp->next;
            secondHead = secondHead->next;
        }
    }

    // attach remaining
    if(firstHead) temp->next = firstHead;
    if(secondHead) temp->next = secondHead;

    return head;
}
void MergeSortLL(Node*&head) {
    if(!head || !head->next) {
        return;
    }

    Node* mid = middleNode(head);
    Node* firstHead = head;
    Node* secondHead = mid->next;

    // fix pointers
    mid->next = nullptr;

    MergeSortLL(firstHead);
    MergeSortLL(secondHead);
    head = Merge(firstHead,secondHead);
}

int main() {
    vector<int> nums = {12,2,3,4,5};
    Node* head = ArrayToLinkedList(nums);
    Traversal(head);  
    MergeSortLL(head); 
    Traversal(head);

}