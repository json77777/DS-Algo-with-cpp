#include<bits/stdc++.h>
using namespace std;

// BF sc -> O(2n)
int tappingWater(vector<int>nums) {
    vector<int>prefixMax (nums.size(),0);
    vector<int>suffixMax (nums.size(),0);

    prefixMax[0] = nums[0];
    for(int i=1; i<nums.size(); i++) {
        prefixMax[i] = max(nums[i], prefixMax[i-1]);
    }
    suffixMax[nums.size()-1] = nums[nums.size()-1];
    for(int i=nums.size()-2; i>=0; i--) {
        suffixMax[i] = max(nums[i], suffixMax[i+1]);
    }

    // actuala algo
    int amount = 0;
    for(int i=0; i<nums.size(); i++) {
        amount += min(prefixMax[i],suffixMax[i]) - nums[i];
    }

    return amount;
}




int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "total units of water trapped: " << tappingWater(height) << endl;
}