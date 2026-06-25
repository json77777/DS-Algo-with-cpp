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
  

vector<vector<int>> ALlTraversal(Node* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    vector<int> pre;
    vector<int> in;
    vector<int> post;
    stack<pair<Node*, int>> st;

    // Use a stack of pairs: node pointer and state.
    // state 1 => node is visited first time (preorder position)
    // state 2 => left subtree processed, now at inorder position
    // state 3 => right subtree processed, now at postorder position
    st.push({root,1});

    while (!st.empty()) {
        auto top = st.top();
        st.pop();

        // pre
        if(top.second == 1) {
            pre.push_back(top.first->val);
            top.second = 2;
            st.push(top); // updates back to the stack
            if(top.first->left) {
                st.push({top.first->left, 1});
            }
        }

        // in
        else if(top.second == 2) {
            in.push_back(top.first->val);
            top.second = 3;
            st.push(top); // updates back to the stack
            if(top.first->right) {
                st.push({top.first->right, 1});
            }
        }

        // post
        else if(top.second == 3) {
            post.push_back(top.first->val);
        }
    }

    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5,nullopt,8,nullopt,nullopt,6,7,9};
    Node* root = constructTree(nums);
    
    vector<vector<int>> ans = ALlTraversal(root);

    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    } 
}