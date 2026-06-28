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

vector<int> distanceK(Node* root, Node* target, int k) {
    // fist find the parent Nodes map
    unordered_map<Node*, Node*> parent;

    queue<vector<Node*>> q; q.push({root});parent[root]=nullptr;
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        // map the ans;
    }   
}

int main() {
    // tree build
    vector<optional<int>> nums = {2, 35, 10, 2, 3, 5, 2};

    
}
