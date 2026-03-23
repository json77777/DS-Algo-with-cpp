#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> nums, int dist, int cows) {
    int cntC = 1;
    int place = nums[0];

    for(int i=1; i<nums.size(); i++) {
        if(nums[i]-place >= dist) {
            cntC++;
            place=nums[i];
        }
        if(cntC >= cows) return true;
    }
    return false;
}


int AggresiveCows_BF(vector<int> nums, int cows) {
    // sort
    sort(nums.begin(),nums.end());
    
    // for if 2 cows are there
    return nums[nums.size()-1] - nums[0];

    // range = -> 1 to (max-min)
    for(int i=1; i<=nums[nums.size()-1] - nums[0]; i++) {
        if(canWePlace(nums,i,cows)) continue;
        else return i-1;
    }
}


int AggresiveCows_BS(vector<int> nums, int cows) {
    // sort
    sort(nums.begin(),nums.end());

    // range = -> 1 to (max-min)
    int low = 1, high = nums[nums.size()-1] - nums[0];

    while(low <= high) {
        int mid = low + (high - low)/2;

        if(canWePlace(nums,mid,cows)) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return high;
}


int main() {
    vector<int> nums = {4,2,1,3,6};
    int cows = 2;
    
    cout << "The maximum possible minimum distance between any two cows is(BRUTE-FORCE): " << AggresiveCows_BF(nums,cows) << endl;
    
    cout << "The maximum possible minimum distance between any two cows is(BINARY-SEARCH): " << AggresiveCows_BS(nums,cows) << endl;
}