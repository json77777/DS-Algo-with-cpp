#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void bfs(vector<vector<int>> &grid, queue<vector<int>> &q, int &time) {
    if (q.empty()) return;
    auto front = q.front();
    q.pop();

    int row = front[0];
    int col = front[1];
    int t = front[2];

    time = max(time, t);

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int nr = row + dr[k];
        int nc = col + dc[k];

        if (nr >= 0 && nr < grid.size() &&
            nc >= 0 && nc < grid[0].size() &&
            grid[nr][nc] == 1) {

            grid[nr][nc] = 2;          // Rot it
            q.push({nr, nc, t + 1});
        }
    }

    bfs(grid, q, time);
}

int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<vector<int>> q;
    int time = 0;

    // Push all rotten oranges (multi-source BFS)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2)
                q.push({i, j, 0});
        }
    }

    bfs(grid, q, time);

    // Check if any fresh orange remains
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return time;
}

int main() {
    auto start = high_resolution_clock::now();

    vector<vector<int>> edges = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    cout << "time taken: " << orangesRotting(edges) << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}


/*
5 6
1 2
1 3
2 4
3 4 
3 5 
4 5
*/