#include<bits/stdc++.h>
// #include "optional.hpp"
#include <optional>
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

void flattenTree(Node*& root, Node* &prev) {
    if (!root) {
        return;
    }

    flattenTree(root->right, prev);
    flattenTree(root->left, prev);

    root->right = prev;
    root->left = nullptr;
    prev = root;
}
void flatten(Node* root) {
    Node* prev=nullptr;
    flattenTree(root,prev);
}


int main() {
    // tree build

    vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    Node* root = constructTree(nums);

    // serialize
    flatten(root);

    while(root) {
        cout << root->val <<   " ";
        root=root->right;
    }
}
