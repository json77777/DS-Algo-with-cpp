// brute -> compute level orfer and return the max size of level

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

// increment
void increment(Node* root, int diff) {
    if(!root) return;
    if(root->left) {
        root->left->val+=diff;
        increment(root->left, diff);
    }
    if(root->right) {
        root->right->val+=diff;
        increment(root->right, diff);
    }
}

void childrenSum(Node* root) {
    if(!root || (!root->left && !root->right)) return ; // leaf; do nothing

    childrenSum(root->left);
    childrenSum(root->right);

    int leftData  = root->left  ? root->left->val  : 0;
    int rightData = root->right ? root->right->val: 0;

    int sum = leftData+rightData;

    // parent has small sum
    if(sum >= root->val) {
        root->val = sum;        
    } else {
        // parent has large sum
        int diff = root->val - sum;
        if(root->left) {
            root->left->val += diff;
            increment(root->left, diff); // affect its left sub tree with += diff
        }
        else if(root->right) {
            root->right->val += diff;
            increment(root->right, diff); // affect its right sub tree with += diff
        }
    }
}

bool childSum2(Node* root) {
    if(!root || (!root->left && !root->right)) return true;
    bool l = childSum2(root->left);
    bool r = childSum2(root->right);

    int leftData  = root->left  ? root->left->val  : 0;
    int rightData = root->right ? root->right->val: 0;

    if(l && r && root->val == leftData+rightData) return true;
    return false;
}

int main() {
    // tree build
    vector<optional<int>> nums = {2, 35, 10, 2, 3, 5, 2};

    Node* root = constructTree(nums);
    
    childrenSum(root);

    cout << "is valid ? " << childSum2(root) << endl;
    
}
