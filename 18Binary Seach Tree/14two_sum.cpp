#include<bits/stdc++.h>
#include "optional.hpp"
// #include <optional>
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

class BSTIterator {
    public:
    stack<Node*> st;
    stack<Node*> prevStack;
    BSTIterator(Node* root) {
        pushLeft(root); // next stack
        pushRight(root); // prev stack
    }
    
    // push left
    void pushLeft(Node* root) {
        while(root) {
            st.push(root);
            root=root->left;
        }
    }

    // push right
    void pushRight(Node* root) {
        while(root) {
            prevStack.push(root);
            root=root->right;
        }
    }

    int next() {
        auto it = st.top();
        st.pop();
        pushLeft(it->right);
        return it == nullptr ? -1 : it->val;
    }

    int prev() {
        auto it = prevStack.top();
        prevStack.pop();
        pushRight(it->left);
        return it == nullptr ? -1 : it->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    bool hasPrev() {
        return !st.empty();
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

// optimal approach tc->o(1), sc->o(height)
bool twoSum(BSTIterator &bst, int k) {
    int i = bst.next();
    int j = bst.prev();
    while(i < j) {
        int sum = i+j;
        if(sum == k) return true;

        if(sum < k) {
            if(!bst.hasNext()) break;
            i=bst.next();
        }
        else {
            if(!bst.hasPrev()) break;
            j=bst.prev();
        }
    }
    return false;
}

int main() {
    // tree build

    vector<optional<int>> nums = {5,3,6,2,4,7};
    Node* root = constructTree(nums);

    // bst iterator
    BSTIterator bst(root);
    
    cout << "is sum present in tree? " << twoSum(bst,9) << endl;
}
