#include <bits/stdc++.h>
using namespace std;

void combinationSum3(int target, vector<int>temp, vector<vector<int>>& ans, int i, int sum, int k) {

    // base case
    if(sum == target && temp.size()==k) {
        ans.push_back(temp); 
        return;
    }

    // pick
    for(int j=i; j<=9; j++) {
        temp.push_back(j);
        combinationSum3(target, temp, ans, j+1, sum+j, k);
        temp.pop_back();
    }
    
}

int main() {
    int n = 45, k = 9;
    vector<int> temp;
    vector<vector<int>> ans;
    combinationSum3(n,temp,ans,1, 0, k);
    for(auto i:ans) {
        for(auto j : i) {
            cout << j << " ";
        } cout << endl;
    }
}