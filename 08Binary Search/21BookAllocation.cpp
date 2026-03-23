#include <bits/stdc++.h>
using namespace std;

int countStudent(vector<int> nums, int pg) {
    int st=1;
    int currMaxPage=0;

    for(int i=0; i<nums.size(); i++) {
        if(currMaxPage + nums[i] <= pg) {
            currMaxPage += nums[i];
        } else {
            st++;
            currMaxPage = nums[i];
        }
    }
    return st;
}

// tc -> O(n^2);
int allocateBooks_BF(vector<int> nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    for(int i=low; i<=high; i++) {
        int student = countStudent(nums,i);
        if(student <= k) {
            return i;
        }
    }
    if(k > nums.size())return -1;
    
}

// tc -> O(nlogn)
int allocateBooks_Optimal(vector<int> nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);

    while(low <= high ) {
        int mid = low + (high-low)/2;

        if(countStudent(nums,mid) <= k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}


int main() {
    vector<int> books = {12, 34, 67, 90};
    int m = 2;

    cout << "brute-force: " << allocateBooks_BF(books,m) << endl;
    cout << "binary-search: "  << allocateBooks_Optimal(books,m) << endl;

}