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

vector<int> morrisInorder(Node* root){
    Node* curr = root;
    vector<int> ans;

    while(curr) {
        if(!curr->left) {
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else {
            Node* prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev=prev->right;
            }
            // create link
            if(prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            }
            // delete link
            else {
                prev->right=nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }   
        }
    }
    return ans;
}


int main() {
    // tree build

    vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    Node* root = constructTree(nums);

    // serialize
    vector<int> ans = morrisInorder(root);
    cout << "morris inorder: ";
    for(auto i:ans) {
        cout << i << " ";
    } cout << endl;
   

    
}
