#include<bits/stdc++.h>
using namespace std;


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dis(m, vector<int>(n,INT_MAX));
    
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

    // set the st 0,0 -> 0
    dis[0][0]=0;

    // take a queue -> we will use Djakstra but with queue.
    queue<vector<int>> q; // {dis, i, j};

    q.push({dis[0][0],0,0});

    // for 8 directions
    vector<int> dx = {-1,-1,-1,0,1,1,1,0};
    vector<int> dy = {-1,0,1,1,1,0,-1,-1};

    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        int d = top[0],x = top[1], y=top[2];

        for(int i=0; i<dx.size(); i++) {
            int newX = x+dx[i];
            int newY = y+dy[i];
            // check if allowed to move to the place
            int newDis = d+1;
            if(newX >= 0 && newX < m && newY >=0 && newY < n && !grid[newX][newY] && newDis < dis[newX][newY]) {
                q.push({newDis, newX, newY});
                dis[newX][newY] = newDis;
            }
        }
    }

    return dis[m-1][n-1]==INT_MAX ? -1 : dis[m-1][n-1];

}

int main() {
    vector<vector<int>> maze = {{1,1,1,1},{1,1,0,1},{1,1,1,1},{1,1,0,0},{1,0,0,0}};

    cout << "min distance src->dest: " << shortestPathBinaryMatrix(maze) << endl;
}