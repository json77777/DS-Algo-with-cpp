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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // base case
    if(!root) {
        return nullptr;
    }

    // cehck cond

    // root > p,q
    if(root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left,p,q);
    }
    // root < p,q
    else if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right,p,q);
    }
    return root;
}


int main() {
    // tree build

    vector<optional<int>> nums = {6,2,8,0,4,7,9,nullopt,nullopt,3,5};
    Node* root = constructTree(nums);
    
    cout << "validate bst: ? " <<  lowestCommonAncestor(root, root->left, root->left->right)->val << endl;

}
