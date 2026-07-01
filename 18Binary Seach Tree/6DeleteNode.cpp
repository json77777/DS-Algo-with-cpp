#include<bits/stdc++.h>
#include "optional.hpp"
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


vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<vector<Node*>> q;
    
    if(!root) return ans;
    // push the root
    q.push({root});

    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        vector<int> temp;
        for(auto i:top) {
            // push the ans in the vector
            temp.push_back(i->val);
        }
        ans.push_back(temp);


        // now fill the que with child
        vector<Node*> temp2;
        for(auto i:top) {
            // push child into queue
            if(i->left) temp2.push_back(i->left);
            if(i->right) temp2.push_back(i->right);
        }
        if(!temp2.empty()) q.push(temp2);
    }

    return ans;
}

Node* largest(Node* root) {
    if(!root) return nullptr;
    if(root->right) return largest(root->right);
    return root;
}

Node* deleteNode(Node* &root ,int val) {
    if(!root) {
       return nullptr;
    }
    
    root->left = deleteNode(root->left,val);
    root->right=deleteNode(root->right,val);

    if(root->val == val) {
        // simple check
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        // delete the right link 

        // attach the left subtrees greater with right;
        Node* leftMax = largest(root->left);
        leftMax->right = root->right;
        return root->left;
    }   
    else return root;
}


int main() {
    // tree build

    vector<optional<int>> nums = {5,3,6,2,4,nullopt,7};
    Node* root = constructTree(nums);
    int key = 3;
    
    root = deleteNode(root,key);
    vector<vector<int>> ans = levelOrder(root);

    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }
}
