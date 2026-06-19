#include<bits/stdc++.h>
using namespace std;

// to calc min jumps to reach end
int canJump(vector<int>& nums) {
    int jumps = 0;
    int l = 0, r = 0;
    while(r < nums.size() - 1) {
        int farthest = r;
        for(int i = l; i <= r; i++) {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        jumps++;
    }
    return jumps;
}

int main() {
    vector<int> nums = {2,3,1,4,1,1,1,2};
    cout << canJump(nums) << endl;
}