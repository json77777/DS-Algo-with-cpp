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

int FloorVal(Node* root, int key) {
    int floor = -1;
    while (root) {
        if (root->val == key) {
            return root->val;
        }
        if (root->val < key) {
            // root could be the floor; check right for something closer
            floor = root->val;
            root = root->right;
        } else {
            // root->val > key, floor must be in left subtree
            root = root->left;
        }
    }
    return floor;
}

int CeilVal(Node* root, int key) {
    int ceil = -1;
    while (root) {
        if (root->val == key) {
            return root->val;
        }
        if (root->val > key) {
            // root could be the ceil; check left for something closer
            ceil = root->val;
            root = root->left;
        } else {
            // root->val > key, ceil must be in right subtree
            root = root->right;
        }
    }
    return ceil;
}


int main() {
    // tree build

    vector<optional<int>> nums = {10,5,15,2,6};
    Node* root = constructTree(nums);

    int key = 7;
    cout << FloorVal(root,key) << endl;
    cout << CeilVal(root,key) << endl;
}
