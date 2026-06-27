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

// not complete..
// https://excalidraw.com/#json=RcitLkQFe3Ay9A9xAcrcM,wUfN8VFMyMviRqQqTNyEHg

void leftTraversal(Node* root, vector<int>&ans) {
    if(!root) return ;
    Node* temp=root;
    while(temp) {
        if(!temp->left && !temp->right) break;
        ans.push_back(temp->val);
        if(temp->left)
            temp=temp->left;
        else
            temp=temp->right;
    }
}

void leafTraversal(Node* root, vector<int>&ans) {
   if(!root) return;

   if(!root->left && !root->right) {
        ans.push_back(root->val);
        return;
   }

   leafTraversal(root->left, ans);
   leafTraversal(root->right, ans);
    
}

void rightTraversal(Node* root, vector<int>&ans) {
    if(!root) return;
    Node*temp=root;
    while(temp) {
        // skip the leaf nodes;
        if(!temp->left && !temp->right) break;
        ans.push_back(temp->val);
        if(temp->right)
            temp=temp->right;
        else    
            temp=temp->left;
    }
    if(ans.size() > 1) reverse(ans.begin(),ans.end());
}

vector<int> boundaryTraversal(Node*root) {
    if(!root) return {};
		// code here
    vector<int> l, leaf, r ;
    if (root->left || root->right)   // don't double-count a single-node tree
        l.push_back(root->val);
    
    leftTraversal(root->left,l);
    leafTraversal(root,leaf);
    rightTraversal(root->right,r);
    l.insert(l.end(),leaf.begin(),leaf.end());
    l.insert(l.end(),r.begin(),r.end());
    return l;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,7,3,nullopt,nullopt,8,nullopt,4,9,nullopt,5,6,10,11};
    Node* root = constructTree(nums);
    
    vector<int> ans = boundaryTraversal(root);

    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;

}
    