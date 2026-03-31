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
void deleteHead(Node*& head) {
    if(head==NULL || head->next==nullptr) {
        head=nullptr;
        return;
    }
    Node* temp = head->next;
    temp->prev=NULL;
    head->next=NULL;
    head=temp;
}
void deleteTail(Node* head) {
    if(head==NULL || head->next==nullptr) {
        head=nullptr;
        return;
    }
    Node* t2 = head;
    while(t2->next) {
        t2=t2->next;
    }
    Node* t1=t2->prev;

    // now operate
    t2->prev=NULL;
    t1->next=NULL;
}
void deleteKthNode(Node*& head, int k) {
    Node* mover = head;
    int c=0;
    if(k==1) return deleteHead(head);
    
    while(mover) {
        c++;
        if(c==k) {
            break;
        }
        mover=mover->next;
    }
    if(k>c) {
        cout << "k value out of range " << endl ;
        return;
    }
    if(mover->next) {
        Node* back = mover->prev;
        Node* forw = mover->next;
        back->next=mover->next;
        forw->prev=mover->prev;
        mover->next=nullptr;
        mover->prev=nullptr;
        delete mover;
    } else {
        return deleteTail(head);
    }
}
void deleteNode(Node* node) {
    Node* front = node->next;
    Node* back = node->prev;

    if(front==nullptr) {
        back->next = node->prev = nullptr;
        delete node;
        return;
    }

    back->next = front;
    front->prev = back;
    node->prev=node->next=nullptr;
    delete node;
    return;
}
void insertHead(Node*& head, int x) {
    if(head==nullptr) {
        head=new Node(x);
        return;
    }

    Node* newNode = new Node(x,head,nullptr);
    head->prev=newNode;
    head=newNode;
    return;
}
void insertBeforeTail(Node* head, int x) {
    Node* curr = head;
    while(curr->next) {
        curr=curr->next;
    }
    Node* prev = curr->prev;

    Node* newNode = new Node(x,curr,prev);
    prev->next=newNode;
    curr->prev=newNode;
}
void insertBeforekthNode(Node* &head, int x, int k) {
    if(k==2) return insertHead(head,x);

    Node* mover=head;
    int c=0;
    while(mover) {
        c++;
        if(c==k-1) {
            Node* forw = mover->next;
            Node* newNode = new Node(x,forw,mover);
            forw->prev=newNode;
            mover->next=newNode;
            return;
        }
        mover=mover->next;
    }

    if(k>c) {
        cout << "Out of Range" << endl;
        return; 
    }
}
void insertBeforeNode(Node* node, int x) {
    Node* back=node->prev;
    Node* temp=new Node(x,node,back);
    back->next=temp;
    node->prev=temp;
}
void reverseDLL(Node*& head) { // O(n)
    Node* curr = head;
    Node* last = nullptr;
    while(curr) {
        last=curr->prev;
        curr->prev=curr->next;
        curr->next=last;
        curr=curr->prev;
    }
    head=last->prev;
}
Node* middleNode(Node* head) { // O(n)
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    Node* head = ArrayToDLL(nums);
    traversal(head);
    deleteHead(head);
    traversal(head);
    deleteTail(head);
    traversal(head);
    deleteKthNode(head, 2);
    traversal(head);
    deleteNode(head->next);
    traversal(head);
    insertHead(head,0);
    traversal(head);
    insertBeforeTail(head,15);
    traversal(head);
    insertBeforekthNode(head,21,2);
    traversal(head);
    insertBeforeNode(head->next->next->next,58);
    traversal(head);
    reverseDLL(head);
    traversal(head);
    cout << "Middle node: " << middleNode(head)->data << endl;
}