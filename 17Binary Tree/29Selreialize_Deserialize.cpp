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

// Encodes a tree to a single string.
string serialize(Node* root) {
    if(!root) return "";
    queue<Node*> q;
    q.push(root);
    string ans;
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        char temp=it->val+'0';
        ans.push_back(temp);

        it->left ? q.push(it->left) : ans.push_back('#');
        it->right ? q.push(it->right) : ans.push_back('#');
    }

    return ans;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    if(data=="") return nullptr;
    
    queue<Node*> q;
    int i=1;
    Node* root = new Node(data[0]-'0'); // push the first digit
    q.push(root);

    while(!q.empty() && i<data.length()) {
        auto top = q.front();
        q.pop();
        // left child
        if(i<data.length()) {
            if(data[i]!='#') {
                top->left = new Node(data[i]-'0');
                q.push(top->left);
            }
            i=i+1;
        }
        // right child
        if(i<data.length()) {
            if(data[i]!='#') {
                top->right = new Node(data[i]-'0');
                q.push(top->right);
            }
            i=i+1;
        }
    }

    return root;
}

int main() {
    // tree build

    vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    Node* root = constructTree(nums);

    // serialize
    string siri = serialize(root);
    cout << "serialize: " << siri << endl;
    // deserialize
    cout << deserialize(siri)->val;

    
}
