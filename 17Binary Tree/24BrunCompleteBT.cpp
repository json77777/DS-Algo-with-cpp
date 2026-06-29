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

void dfs(Node* root, unordered_map<Node*,Node*> &parent, int &minTime, int currTime, unordered_map<Node*,bool> &burnt) {
    // edge case
    if(!root || burnt[root]) {
        return ;
    }
    // mark burnt, calc minTime
    burnt[root]=1;
    minTime = max(minTime,currTime);

    // expand
    dfs(root->left,parent,minTime,currTime+1,burnt);
    dfs(root->right,parent,minTime,currTime+1,burnt);
    dfs(parent[root],parent,minTime,currTime+1,burnt);

}

bool find(Node* root, int target, Node* &t) {
    if(!root) return false;
    if(root->val == target) {
        t=root; return true;
    }

    return find(root->left,target,t) || find(root->right,target,t);

}

int minTime(Node* root, int target) {
    // create a parent mapping
    unordered_map<Node*,Node*> parent;
    queue<Node*> q;
    q.push(root); parent[root] = nullptr;
    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        if(top->left) {
            parent[top->left]=top;
            q.push(top->left);
        }
        if(top->right) {
            parent[top->right]=top;
            q.push(top->right);
        }
    }

    // second step reach taget
    Node* t=nullptr; 
    bool found = find(root,target, t);
    if(!found) return -1;

    // do dfs , keep track of time, burnt
    unordered_map<Node*,bool> burnt;
    int minTime=0;
    
    dfs(t,parent,minTime,0,burnt);

    return minTime;

}

int main() {
    // tree build
    vector<optional<int>> nums = {1, 2, 3, 4, 5, 6, 7};

    Node* root = constructTree(nums);
    int target = 2;
    cout << "minimum time to burn the tree: " << minTime(root,target) << endl;
}
