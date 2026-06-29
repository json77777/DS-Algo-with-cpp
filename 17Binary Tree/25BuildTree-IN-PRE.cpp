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

Node* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& inMap, int stIn, int stPre, int endIn, int endPre) {
    // base case
    if(stIn > endIn || stPre > endPre) return nullptr;

    int rootVal = preorder[stPre];          // first element of preorder range = root
    Node* root = new Node(rootVal);

    int mid = inMap[rootVal];               // root's position in the full inorder array
    int leftSize = mid - stIn;              // how many nodes are in the left subtree

    root->left  = build(preorder, inorder, inMap,
                         stIn, stPre + 1,             // inorder/preorder start for left
                         mid - 1, stPre + leftSize);  // inorder/preorder end for left

    root->right = build(preorder, inorder, inMap,
                         mid + 1, stPre + leftSize + 1,  // start for right
                         endIn, endPre);                 // end for right

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // create a map
    unordered_map<int,int> inMap; // val,ind
    for(int i=0; i<inorder.size(); i++) {
        inMap[inorder[i]]=i;
    }

    int stIn=0,stPre=0,endIn = inorder.size()-1, endPre=preorder.size()-1;

    return build(preorder,inorder,inMap,stIn,stPre,endIn,endPre);

}

int main() {
    // tree build
    // vector<optional<int>> nums = {1, 2, 3, 4, 5, 6, 7};

    // Node* root = constructTree(nums);
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    Node* root = buildTree(preorder, inorder);
    cout << root->val << endl;
}
