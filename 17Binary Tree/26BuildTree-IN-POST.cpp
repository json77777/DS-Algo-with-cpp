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

Node* build(vector<int>& postorder, vector<int>& inorder, unordered_map<int,int>& inMap, int stIn, int stPost, int endIn, int endPost) {
    // base case
    if(stIn > endIn || stPost > endPost) return nullptr;

    int rootVal = postorder[endPost];          // last element of postorder range = root
    Node* root = new Node(rootVal);

    int mid = inMap[rootVal];               // root's position in the full inorder array
    int leftSize = mid - stIn;              // how many nodes are in the left subtree

    root->left  = build(postorder, inorder, inMap,
                         stIn, stPost,             // inorder/postorder start for left
                         mid-1, stPost + leftSize-1);  // inorder/postorder end for left

    root->right = build(postorder, inorder, inMap,
                         mid + 1, stPost + leftSize ,  // start for right
                         endIn, endPost-1);                 // end for right

    return root;
}

Node* buildTree(vector<int>& postorder, vector<int>& inorder) {
    // create a map
    unordered_map<int,int> inMap; // val,ind
    for(int i=0; i<inorder.size(); i++) {
        inMap[inorder[i]]=i;
    }

    int stIn=0,stPost=0,endIn = inorder.size()-1, endPost=postorder.size()-1;

    return build(postorder,inorder,inMap,stIn,stPost,endIn,endPost);

}

int main() {
    // tree build
    // vector<optional<int>> nums = {1, 2, 3, 4, 5, 6, 7};

    // Node* root = constructTree(nums);
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    vector<int> inorder = {40, 20 , 50, 10, 60, 30};
    Node* root = buildTree(postorder, inorder);
    cout << root->val << endl;
}
