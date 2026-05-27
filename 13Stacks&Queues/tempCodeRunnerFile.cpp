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