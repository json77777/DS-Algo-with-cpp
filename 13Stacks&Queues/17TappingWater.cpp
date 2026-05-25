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

int totalWater(vector<int>nums) {
    // Two-pointer solution: track the highest wall seen so far on both sides.
    int lMax = 0, rMax = 0, total = 0, l = 0, r = nums.size()-1;

    while(l < r) {
        // Process the side with the smaller height; that side is the limiting one.
        if(nums[l] <= nums[r]) {
            // Water can be trapped only if the current bar is below the left max.
            if(lMax > nums[l]) {
                total += lMax - nums[l];
            }
            else {
                // Update left boundary when a taller bar is found.
                lMax = nums[l];
            }
            l++;
        }

        else {
            // Same logic for the right side.
            if(rMax > nums[r]) {
                total += rMax - nums[r];
            }
            else {
                // Update right boundary when a taller bar is found.
                rMax = nums[r];
            }
            r--;
        }
    }

    return total;
}


int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "total units of water trapped: " << tappingWater(height) << endl;
    cout << "total units of water trapped: " << totalWater(height) << endl;
}