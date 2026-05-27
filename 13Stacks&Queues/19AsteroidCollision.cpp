#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &nums) {
    vector<int> ans;

    for(int i=0 ;i<nums.size(); i++) {
        if(nums[i] > 0) {
            ans.push_back(nums[i]);
        }

        // skip
        else if (!ans.empty() && ans.back() > 0 && abs(ans.back()) > abs(nums[i])) {
            continue;
        }

        // equal
        else if(!ans.empty() && ans.back() > 0 && abs(ans.back()) == abs(nums[i])) {
            ans.pop_back();
            continue;
        }
        
        // currently a negetive
        // negative eats positives
        else {
            while(!ans.empty() && ans.back() > 0 && abs(ans.back()) < abs(nums[i])) {
                ans.pop_back();
            }
            // equal: top also dies
            if(!ans.empty() && ans.back() > 0 && abs(ans.back()) == abs(nums[i])) {
                ans.pop_back();
            }
            else if(ans.empty() || ans.back() < 0) {
                ans.push_back(nums[i]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-2,-1,1,2};
    vector<int> ans = asteroidCollision(nums);

    for(auto i:ans) {
        cout << i << " ";
    }cout << endl;
}