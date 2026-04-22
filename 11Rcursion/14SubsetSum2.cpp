#include <bits/stdc++.h>
using namespace std;

void combinationSum2(vector<int>nums, vector<int>temp,vector<vector<int>>& ans, int i) {

    // base case
    if(i == nums.size()) {
        ans.push_back(temp);
        return;
    }
    // pick (same index to allow duplicates)
    temp.push_back(nums[i]);
    combinationSum2(nums,temp, ans,i+1);
    
    // skip (move to next index)
    temp.pop_back();
    combinationSum2(nums, temp, ans,i+1);
    
}

void combinationSum2_optimal(vector<int>&nums, vector<int>temp, vector<vector<int>>& ans, int i) { // takes uniquw subs
    ans.push_back(temp);
    if(i>=nums.size()) {
        return;
    }

    for(int j=i; j<nums.size(); j++) {
        if(j > i && nums[j] == nums[j-1]) {
            continue;
        }
        else {
            temp.push_back(nums[j]);
            combinationSum2_optimal(nums,temp, ans, j+1);
            temp.pop_back();
        }

    }
}


int main() {
    vector<int> nums = {4,4,4,1,4};
    vector<int> temp;
    vector<vector<int>> ans;
    // combinationSum2(nums,temp,ans,0); generate all subsets
    sort(nums.begin(),nums.end());
    combinationSum2_optimal(nums,temp,ans,0);
    for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }
}