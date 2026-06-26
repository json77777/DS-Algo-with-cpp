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


int height(Node* root) {
    if(!root) return 0;
    // right height
    int l = height(root->left);
    // left height
    int r = height(root->right);

    // the left or right one is no balanced
    if(l == -1 || r == -1) return -1;
    // checks
    if(abs(l-r) > 1) return -1;
    // else return tree
    return 1+max(l,r);
}

bool isBalanced(Node*root) {
    return height(root) != -1;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,2,3,nullopt,nullopt,3,4,nullopt,nullopt,4};
    Node* root = constructTree(nums);
    
    cout << "balanced tree? " << isBalanced(root); 

}