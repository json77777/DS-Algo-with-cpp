#include<bits/stdc++.h>
#include "optional.hpp"
// #include<optional>
using namespace std;

class Node {
    public:
    int val;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int x) {
        this->val=x;
    }

    Node(int x, Node* l, Node* r) {
        this->val=x;
        this->left=l;
        this->right=r;
    }

};

Node* constructTree(const vector<optional<int>>& nums) {
    if (nums.empty() || !nums[0].has_value())
        return nullptr;

    Node* root = new Node(*nums[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        Node* curr = q.front();
        q.pop();

        // left child
        if (i < nums.size()) {
            if (nums[i].has_value()) {
                curr->left = new Node(*nums[i]);
                q.push(curr->left);
            }
            ++i;
        }

        // right child
        if (i < nums.size()) {
            if (nums[i].has_value()) {
                curr->right = new Node(*nums[i]);
                q.push(curr->right);
            }
            ++i;
        }
    }

    return root;
}

// explaination
// https://excalidraw.com/#json=bDWmOs9V5kPEhW8NpgOtu,2WsWLcxXoQ-BnTLa-tSj0A

bool isSameTree(Node* p, Node* q) {
    if(!p && !q) return true;
    if((!p && q) || (p && !q)) return false;
    if(p->val != q->val) return false;

    bool l = isSameTree(p->left,q->left);
    bool r = isSameTree(p->right,q->right);

    return l && r;
}


int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5};
    vector<optional<int>> nums2 = {1,2,3,4,5};
    Node* root = constructTree(nums);
    Node* root2 = constructTree(nums2);
    
    cout << "Is same tree? " << isSameTree(root,root2) << endl; 

}
    