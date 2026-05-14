#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>&nums) {
    vector<int> ans;

    int temp=0;
    for(auto i:nums) {
        temp=temp^i;
    }

    // algo
    int xored = temp&temp-1;
    temp=temp^xored;

    // now temp has right most bit set

    // now seperate numbers based on right most bit
    int buck1=0, buck2=0;

    for(auto i:nums) {
        // set store in buck1 
        if(i & temp) buck1 ^= i;
        else buck2 ^= i;
    } 
    ans.push_back(buck1);
    ans.push_back(buck2);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    
    vector<int> ans = singleNumber(nums);
    
    cout << "The single numbers in given array are: " << ans[0] << " and " << ans[1] << endl;
    
}