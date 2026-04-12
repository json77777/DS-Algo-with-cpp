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
void pairSum(Node* head, int target) {
    vector<pair<int,int>> ans;

    Node* left=head;
    Node* right=head;
    while(right->next) {
        right=right->next;
    }

    while(left && right) {
        int sum = right->data + left->data;
        if(right->data < left->data) break; // breaking condition imp
        if(sum == target) {
            ans.push_back({left->data, right->data});
            left=left->next;
            right=right->prev;
        }
        else if(sum > target) {
            right=right->prev;
        }
        else {
            left=left->next;
        }
    }

    for(auto i:ans) {
        cout << i.first << " " << i.second << endl;
    }
}

int main() {
    vector<int> nums = {1,2,3,4,9};
    Node* head = ArrayToDLL(nums);
    traversal(head);
    pairSum(head,5);

}