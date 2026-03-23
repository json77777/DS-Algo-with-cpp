#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& nums, int capacity, int days) {
    int sum = 0;
    int d = 1;

    for(int i = 0; i < nums.size(); i++) {
        if(sum + nums[i] <= capacity) {
            sum += nums[i];
        } else {
            d++;
            sum = nums[i];
        }
    }
    return d <= days;
}


int shipWithinDays(vector<int> nums, int days) {
    // mini -> max wt;
    // max  -> summ of all wts;

    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(possible(nums,mid,days)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


int main() {
    vector<int> nums = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;

    cout << "minimum ship capacity to transport all weights in " << days << " days are: " << shipWithinDays(nums, days);
}