#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> nums, int day, int k, int m) {
    int c=0;
    int noOfB=0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] <= day) c++;
        else {
            noOfB += c/k;
            c=0; // reset count for consecutive approach
        }
    }
    noOfB += c/k;

    // check criteria
    if(noOfB >= m) return true;
    else return false;
}

int minDays(vector<int> nums, int k, int m) {

    if(nums.size() < k*m) return -1;

    int low = *min_element(nums.begin(),nums.end());
    int high = *max_element(nums.begin(),nums.end());

    while(low <= high) {
        int mid = low+(high-low)/2;
        if(possible(nums,mid,k,m)) {
            // may be the possible ans
            high=mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}


int main() {
    // k -> adjacent bloomed roses to make a single bouquet
    // m -> no. of bouquets
    vector<int> nums = {7, 7, 7, 7, 13, 11, 12, 7};
    int m=2, k=3;

    cout << "Min days to make " << m << " bouquets with " << k << " flowers each: " << minDays(nums,k,m);
}