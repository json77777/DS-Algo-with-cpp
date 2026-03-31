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
bool checkLoop_BF(Node* head) {
    unordered_map<Node* , int> mp;
    Node* temp=head;
    while(temp!=NULL) {
        if(mp.find(temp)==mp.end()) {// not present
            mp[temp]++;
        } else {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
bool checkLoop_Optimal(Node* head) {
    Node* slow=head;
    Node* fast = head;
    while(fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
Node* startLoop(Node* head) { // tc->O(n),sc->O(n)
    unordered_map<Node*, int> mp;
    Node* temp=head;

    while(temp) {
        if(mp.find(temp)==mp.end()) {
            mp[temp]++;
        }
        else{
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
Node* startLoop_Optimal(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            //step2
            slow=head;
            while(slow!=fast) {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
int LoopLength_BF(Node* head) { // tc->O(n),sc->O(n)
    Node* temp=head;
    int c=0;
    unordered_map<Node*,int>mp;
    while(temp) {
        if(mp.find(temp)==mp.end()) { // not present
            c++;
            mp[temp]=c;
        } else {
            // move c to one more
            return (c+1)-mp[temp];
        }
        temp=temp->next;
    }
    return 0;
}
int LoopLength_Optimal(Node* head) { // O(N + L)
    Node*slow=head;
    Node*fast=head;
    while(fast && fast->next) {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) {
            Node* temp = slow->next;
            int c = 1; // for counting skipped node
            while(temp != slow) {
                c++;
                temp = temp->next;
            }
            return c;
        }
    }
    return 0;
}


int main() {
    Node* head = new Node(1,nullptr);
    head->next = new Node(2,nullptr);
    head->next->next = new Node(3,nullptr);
    head->next->next->next = new Node(15,nullptr);
    head->next->next->next->next = new Node(4,nullptr);
    head->next->next->next->next->next = new Node(13,nullptr);
    head->next->next->next->next->next->next = new Node(6,nullptr);
    head->next->next->next->next->next->next->next = new Node(7,nullptr);
    head->next->next->next->next->next->next->next->next = new Node(8,nullptr);
    head->next->next->next->next->next->next->next->next->next = new Node(9,head->next->next->next);
    // traversal(head); -> infinte loops
    cout << "Loop present(BF): " << checkLoop_BF(head) << endl;
    cout << "Loop present(Optimal): " << checkLoop_Optimal(head) << endl;
    cout << "Starting point of Loop(BF): " << startLoop(head)->data << endl;
    cout << "Starting point of Loop(Optimal): " << startLoop_Optimal(head)->data << endl;
    cout << "Length of Loop(BF): " << LoopLength_BF(head) << endl;
    cout << "Length of Loop(Optimal): " << LoopLength_Optimal(head) << endl;
}