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

void inorder(Node* root, vector<int>&in) {
    if(!root) return;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
}

Node* buildBST(int st, int end, vector<int> total) {
    if(st > end) return nullptr; // return; base case
    int mid = st+(end-st)/2;

    Node* root = new Node(total[mid]);

    root->left = buildBST(st,mid-1,total);  // left -> [st,mid-1]
    root->right = buildBST(mid+1,end,total); // right -> [mid+1,end]
    return root;
}

Node* mergeBST(Node* root1, Node* root2) {
    if(!root1) return root2;
    if(!root2) return root1;

    // create inorder
    vector<int> in1,in2;
    inorder(root1,in1);
    inorder(root2,in2);

    // create a new merged arr
    vector<int> total;
    int i=0,j=0;
    while(i<in1.size() && j<in2.size()) {
        if(in1[i] <= in2[j]) total.push_back(in1[i++]);
        else total.push_back(in2[j++]);
    }
    while(i < in1.size()) {
        total.push_back(in1[i++]);
    }
    while(j < in2.size()) {
        total.push_back(in2[j++]);
    }

    // build the tree
    return buildBST(0,total.size()-1,total);
}



int main() {
    // tree build

    vector<optional<int>> nums = {3, 1, 5};
    vector<optional<int>> nums2 = {4,2,6};
    Node* root = constructTree(nums);
    Node* root2 = constructTree(nums2);
    
    Node* rBst = mergeBST(root,root2);

    vector<vector<int>> ans = levelOrder(rBst);

    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }

}
