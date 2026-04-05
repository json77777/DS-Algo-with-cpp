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
void sort012(Node* &head) {

    if(!head || !head->next) {
        return;
    }

    Node* zeroHead=new Node(-1);
    Node* zero=zeroHead;
    Node* oneHead=new Node(-1);
    Node* one=oneHead;
    Node* twoHead=new Node(-1);
    Node* two=twoHead;

    Node* temp=head;
    while(temp) {
        if(temp->data==0) {
            zero->next=temp;
            zero = temp;
        }
        else if(temp->data==1) {
            one->next=temp;
            one = temp;
        }
        else if(temp->data==2) {
            two->next=temp;
            two = temp;
        }
        temp=temp->next;
    }
    //remove -1 form all
    zeroHead=zeroHead->next;
    oneHead=oneHead->next;
    twoHead=twoHead->next;
    // links them
    zero->next=oneHead;
    one->next=twoHead;
    two->next=nullptr;
    head=zeroHead;
}

int main() {
    vector<int> nums = {0,2,1,0,1,1,2,0,0,2,1,2,0};
    Node* head = ArrayToLinkedList(nums);
    Traversal(head);  
    // MergeSortLL(head); 
    sort012(head);
    Traversal(head);

}