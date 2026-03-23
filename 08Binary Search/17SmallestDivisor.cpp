#include <bits/stdc++.h>
using namespace std;

bool possible_divisor(vector<int> nums, int limit, int d) {
    int sum = 0;
    for(auto i:nums) {
        sum += ceil((double)i/d);
    }
    if(sum <= limit) return true;
    else return false; 
}

int smallestDivisor(vector<int> nums, int limit) {
    int low = 1;
    int high = *max_element(nums.begin(),nums.end());

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(possible_divisor(nums,limit,mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int limit = 8;
    cout << "The smallest divisor for limit " << limit << " is: " << smallestDivisor(nums, limit) << endl;
}