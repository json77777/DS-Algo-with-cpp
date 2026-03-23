#include <bits/stdc++.h>
using namespace std;

double GasStationSolver_BF(vector<int> nums, int k) {

    int n=nums.size();
    // no. of spots
    vector<int> howMany(n-1,0);

    for(int gasStation=0; gasStation<k; gasStation++) {
        double maxDis = -1;
        int maxInd=-1;

        for(int i=0; i<n-1; i++) {
            double dis = (nums[i+1]-nums[i]) / (double)(howMany[i]+1);
            if(dis > maxDis) {
                maxDis = dis;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    double  ans = -1;
    for(int i=1; i<n-1; i++) {
        double dis = (nums[i+1]-nums[i]) / (double)(howMany[i]+1);
        ans = max(ans, dis);
    }
    return ans;
}

// tc -> O(nlogn)
long double GasStationSolver_OPTIMAl(vector<int> nums, int k) {

    int n=nums.size();
    // no. of spots
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double, int>> pq;

    // insert the section distance
    for(int i=0; i<n-1; i++) {
        pq.push({(double)(nums[i+1]-nums[i]), i});
    }

    // placing gas stations
    for(int gasStation=0; gasStation<k; gasStation++) {
        auto tp = pq.top();
        pq.pop(); 
        int gasIndex = tp.second;
        howMany[gasIndex]++;
        long double newDist = (nums[gasIndex+1] - nums[gasIndex]) / (long double)(howMany[gasIndex] + 1);
        pq.push({newDist, gasIndex});
    }

    // after this the howmany are set
    return pq.top().first;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k=9;

    cout << "the maximum difference between adjacent gas stations is (BF): " << GasStationSolver_BF(nums,k) << endl;
    cout << "the maximum difference between adjacent gas stations is (OPTIMAL): " << GasStationSolver_OPTIMAl(nums,k) << endl;
}