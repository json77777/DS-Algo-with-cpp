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

void traverse(Node* root, map<int,map<int,vector<int>>> &mp, int col, int row) {
    if(!root) return;
    mp[col][row].push_back(root->val);
    traverse(root->left, mp, col-1,row+1);
    traverse(root->right, mp, col+1,row+1);
}

vector<int> topView(Node* root) {
    map<int,map<int,vector<int>>> mp;

    // set corrd at 0,0 (col,row)

    traverse(root,mp,0,0);
    vector<int> ans;

    // map contains the ans for verticle order traversal -> take the first
    for(auto [col, rowVals]:mp) {
        for(auto [row,vals]:rowVals) {
            ans.push_back(vals[0]); // take the first item and pop out
            break;
        }
    }

    return ans;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,10,9,11,nullopt,5,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,nullopt,6};

    Node* root = constructTree(nums);
    
    vector<int> ans = topView(root);

    for(auto i:ans) {
        cout << i << " ";
    }

}
    