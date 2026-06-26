#include<bits/stdc++.h>
#include "optional.hpp"
// #include<optional>
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

// explaination
// https://excalidraw.com/#json=Oz4z16oc1m5WSzTV344OX,cZyyRoTCIMPCmWti9NZ2yA

int calcPath(Node* root, int &best) {
    if(!root) return 0;
    int l =calcPath(root->left, best);
    int r =calcPath(root->right, best);
    // ignore negetive paths
    l = max(l,0);
    r = max(r,0);
    best = max(best, root->val+best);
    return root->val + max(l,r);
}

int maxPathSum(Node* root) {
    int best=0;
    calcPath(root, best);
    return best;
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5};
    Node* root = constructTree(nums);
    
    int best=0;
    calcPath(root,best);
    cout << "diameter of the tree " << calcPath(root,best); 

}
    