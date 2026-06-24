#include<bits/stdc++.h>
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

void preorder(Node* root, vector<int>&ans) {
    if(!root) return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void inorder(Node* root, vector<int>&ans) {
    if(!root) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

void postorder(Node* root, vector<int>&ans) {
    if(!root) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

void IterativePostorder(Node* root, vector<int> &ans) {
    if(!root) return;
    stack<Node*> s1, s2;

    //push root elm to s1
    s1.push(root);
    while(!s1.empty()) {
        Node* top = s1.top();
        s1.pop();
        s2.push(top);
        if(top->left) s1.push(top->left);
        if(top->right) s1.push(top->right);
    }
    // s2 has ans. push it to ans;
    while(!s2.empty()) {
        ans.push_back(s2.top()->val);
        s2.pop();
    }
}   

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    
    
    
}

int main() {
    // tree build
    vector<optional<int>> nums = {1,2,3,4,5,nullopt,8,nullopt,nullopt,6,7,9};
    Node* root = constructTree(nums);
    
    vector<int> ans;
    // preorder(root, ans);
    // inorder(root, ans);
    // postorder(root,ans);

    IterativePostorder(root,ans);
    // print
    cout << "iterative post-order traversal: ";
    for(auto i: ans) {
        cout << i << " ";
    }cout << endl;
}