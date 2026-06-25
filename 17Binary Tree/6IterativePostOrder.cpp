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
  

vector<int> IterativePostOrder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        // go as far left as possible, pushing along the way
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        Node* temp = st.top()->right;

        if(temp == nullptr) {
            temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            while(!st.empty() && temp==st.top()->right) {
                temp=st.top();
                st.pop();
                ans.push_back(temp->val);
            }
        }
        else {
            curr = temp;
        }
    }
    return ans;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5,nullopt,8,nullopt,nullopt,6,7,9};
    Node* root = constructTree(nums);
    
    vector<int> ans = IterativePostOrder(root);

    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;
}