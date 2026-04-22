#include <bits/stdc++.h>
using namespace std;

bool generateSubseq_sumK(vector<int>nums,int target, vector<int>temp,vector<vector<int>>& ans, int i) {
    // base case
    if( i==nums.size()) {
        if(accumulate(temp.begin(),temp.end(),0) == target) {
            ans.push_back(temp);
            return true;
        }
        return false;
    }

    // take
    temp.push_back(nums[i]);
    if(generateSubseq_sumK(nums,target,temp,ans,i+1) == true) return true;
    
    // skip
    temp.pop_back();
    if(generateSubseq_sumK(nums,target,temp,ans,i+1) == true) return true;

    return false;
    
}

int main() {
    vector<int> nums = {1, 2, 1, 3};
    int target = 3;
    vector<int> temp;
    vector<vector<int>> ans;
    generateSubseq_sumK(nums,target,temp,ans,0);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}