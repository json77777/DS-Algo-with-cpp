#include<bits/stdc++.h>
using namespace std;

// fun(weights, goal) counts how many people have a weight less than or equal to the goal (here, 70 kg).
// fun(weights, goal-1) counts how many people have a weight less than or equal to goal - 1 (here, 69 kg).
// By subtracting the two, you get the number of people who weigh exactly the goal weight.
// Why it works:
// This technique isolates the exact count of people (or items) at the goal value by subtracting the number of items below the goal from the number of items less than or equal to the goal. It's easier than directly counting "exact" matches in some problems, which is why this approach is useful.

int f(vector<int>&nums, int k) { // count subarrays less than equal to k
    if(k<0) return 0;
    int l=0,r=0, sum=0, count=0;
    while(r<nums.size()) {
        sum+=nums[r];
        while(sum > k) {
            sum = sum - nums[l];
            l++;
        }
        count = count+= (r-l+1);
        r++;
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal){
    return f(nums,goal)-f(nums,goal-1);
}

int main() {
    vector<int> nums = {1,0,0,1,1,0};
    int k=2;
    cout << "binary subaarys with sum k: " << numSubarraysWithSum(nums,k) << endl;
    
}