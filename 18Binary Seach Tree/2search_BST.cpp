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

Node* searchBST(Node* root, int val) {
    if(!root) return nullptr;
    if(root->val == val) return root;
    if(root->val > val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}


int main() {
    // tree build

    vector<optional<int>> nums = {4,2,7,1,3};
    Node* root = constructTree(nums);

    if(searchBST(root,1)!=nullptr) {
        cout << "found" << endl;
    } else cout << "Not found" << endl;
}
