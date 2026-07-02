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

int kthSmallest(Node* root, int k, int &i) {
    if(!root) return -1;
    int l = kthSmallest(root->left,k,i);

    if(l!=-1) {
        return l;
    }
    i++;
    if(i==k) {
        return root->val;
    }

    return kthSmallest(root->right,k,i);
}

int kthLargest(Node* root, int k, int &j) {
    if(!root) return -1;
    int r = kthLargest(root->right,k,j);

    if(r!=-1) {
        return r;
    }
    
    j++;
    if(j==k) {
        return root->val;
    }
    return kthLargest(root->left,k,j);

}

pair<int,int> kth_smallest_largest(Node* root, int k) {
    int i=0,j=0;
    int l= kthSmallest(root,k,i);
    int r= kthLargest(root,k,j);
    return make_pair(l,r);
}


int main() {
    // tree build

    vector<optional<int>> nums = {5, 3, 6, 2, nullopt, nullopt, nullopt, 1};
    Node* root = constructTree(nums);
    int k = 1;
    pair<int,int> ans = kth_smallest_largest(root,k);
    cout << "kth smallest element: " << ans.first << endl;
    cout << "kth largest element: " << ans.second << endl;
    // vector<vector<int>> ans = levelOrder(root);

    // for(auto i:ans) {
    //     for(auto j:i) {
    //         cout << j << " ";
    //     } cout << endl;
    // }
}
