#include<bits/stdc++.h>
using namespace std;

bool checkMinHeap(vector<int>&nums, int i) {
    int n=nums.size();
    int l=2*i+1;
    int r=2*i+2;
    if(l > n || r > n) return 1;
    // false cond
    if(nums[i] > nums[l] || nums[i] > nums[r]) {
        return 0;
    }

    // recurr
    return checkMinHeap(nums,l) && checkMinHeap(nums,r);
}

int main() {
    vector<int> nums = {10, 20, 30, 25, 15};
    cout << "minHeap? : " << checkMinHeap(nums, 0) << endl;
}