#include <bits/stdc++.h>
using namespace std;

void addOperators(string &nums, int target, int i, int eval, int prev, vector<string> &ans, string temp) {

    if(i==nums.size()) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        return;
    }

    
}

int main() {
    string nums = "123";
    int target = 6;
    vector<string> ans;
    string temp;
    
    addOperators(nums,target,0,0,0,ans,temp);
    
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }
}