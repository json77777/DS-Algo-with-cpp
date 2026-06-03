#include <bits/stdc++.h>
using namespace std;

// tc -> O(n*n)*log3
// sc -> O(3);
int fruitsBasket_BF(vector<int>&nums,int basket) {
    int len=0;
    for(int i=0; i<nums.size(); i++) {
        set<int> st;
        for(int j=i; j<nums.size(); j++) {
            st.insert(nums[j]);
            if(st.size()<=basket) {
                len=max(len,j-i+1);
            }
            else break;
        }
    }

    return len;
}
// TC -> O(2n) worst
int fruitsBasket_Better(vector<int>&nums,int basket) {
    int len=0;
    map<int,int> mp;//(int, freq);

    int l=0,r=0;
    while(r<nums.size()) {
        mp[nums[r]]++;
        while(mp.size() > basket) {
            mp[nums[r]]--;
            if(mp[nums[r]] == 0) mp.erase(nums[r]);
            l++;
        }
        // find length
        len = max(len,r-l+1);
        r++;
    }

    return len;
}
// TC -> O(n)
int fruitsBasket_Optimal(vector<int>&nums,int basket) {
    int len=0;
    map<int,int> mp;//(int, freq);

    int l=0,r=0;
    while(r<nums.size()) {
        mp[nums[r]]++;
        if(mp.size() > basket) {
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            if(mp.find(nums[l]) != mp.end()) {
                mp[nums[l]]--;
                l++;
            }
            r++;
        }
        // find length
        len = max(len,r-l+1);
        r++;
    }

    return len;
}

int main() {
    int basket = 2;
    vector<int> nums = {1, 2, 1};
    cout << "fruits basket(BF): " << fruitsBasket_BF(nums, basket) << endl; 
    cout << "fruits basket(Better): " << fruitsBasket_Better(nums, basket) << endl; 
    cout << "fruits basket(Oprimal): " << fruitsBasket_Optimal(nums, basket) << endl; 
}