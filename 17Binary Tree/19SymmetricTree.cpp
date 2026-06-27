#include<bits/stdc++.h>
// #include "optional.hpp"
#include<optional>
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

bool mirror(Node* t1, Node* t2) {
    if(!t1 && !t2) return true;
    if((!t1 && t2) || (t1 && !t2)) return false;
    if(t1->val != t2->val) {
        return false;
    }

    return mirror(t1->left,t2->right) && mirror(t1->right,t2->left);
}
bool isSymmetric(Node* root) {
    if(!root) return false;
    return mirror(root->left,root->right);
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,10,9,11,nullopt,5,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,6};

    Node* root = constructTree(nums);
    
    cout << "Symmetric tree ? " << isSymmetric(root) << endl;

}
    