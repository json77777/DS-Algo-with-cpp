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

bool printPath(Node* root, int data, vector<int>& ans) {
    if(!root) return false;
    ans.push_back(root->val);
    if(root->val == data) return true;

    if( printPath(root->left,data,ans) || printPath(root->right,data,ans) ) 
        return true;

    // backtrack
    ans.pop_back();
    return false;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1, 2, 3, 4, 5, nullopt, nullopt, 6,7};

    Node* root = constructTree(nums);
    
    vector<int> ans ;
    if(printPath(root, 7, ans)) { // no two nodes have same data value
        for(auto i:ans) {
            cout << i << " ";
        }cout << endl;
    } else {
        cout << "no route found" << endl;
    }
}
