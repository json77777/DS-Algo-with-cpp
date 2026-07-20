#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    if(heights.empty() || heights[0].empty()) return 0;
    int m = heights.size(),  n = heights[0].size();
    vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
    dis[0][0] = 0;

    // minheap
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
    minHeap.push({0,{0,0}}); // push the starting element


    // moving directions
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!minHeap.empty()) {
        auto top = minHeap.top();

        int d = top.first;
        int r = top.second.first, c = top.second.second;

        minHeap.pop();

        if(r == m-1 && c == n-1) return d;

        for(int i=0; i<4; i++) {
            int newR = r+dr[i];
            int newC = c+dc[i];

            if(newR >= 0 && newR < m && newC >=0 && newC < heights[0].size()) {
                // calc new difference
                int diff = abs(heights[r][c] - heights[newR][newC]);
                // take max diff
                int newEffort = max(d, diff);
                // store in dis array to maitain track with new diff
                if(newEffort < dis[newR][newC]) {
                    dis[newR][newC] = newEffort;
                    minHeap.push({newEffort, {newR, newC}});
                }
            }
        }
    }
    return dis[m-1][n-1];
}

int main() {
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};

    cout << "min effort from st to end: " << minimumEffortPath(heights) << endl;
}