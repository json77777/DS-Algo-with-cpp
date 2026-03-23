#include <bits/stdc++.h>
using namespace std;
 
int possible(vector<int> nums, int time,int k) {
    int painters=1;
    int timeNeeded = 0;

    for(auto i:nums) {
        if(timeNeeded+i <= time) {
            timeNeeded+=i;
        }
        else {
            painters++;
            timeNeeded=i;
        }
    }
    return painters;
}

int PaintersProblem(vector<int> nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(possible(nums,mid,k) <= k) {
            high=mid-1;
        } else {
            low = mid+1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int k=3;

    cout << PaintersProblem(nums,k) << endl;
}