#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void dfs(vector<vector<int>>& grid, int sr, int sc, int color, int newColor) {
    grid[sr][sc] = newColor;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int nr = sr + dr[k];
        int nc = sc + dc[k];

        if (nr >= 0 && nr < grid.size() &&
            nc >= 0 && nc < grid[0].size() &&
            grid[nr][nc] == color) {

            grid[nr][nc] = newColor;          // color it with new color
            dfs(grid,nr,nc,color,newColor);   // call for neighbours
        }


    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();

    if(image[sr][sc]!=color) {
        dfs(image,sr,sc,image[sr][sc],color);
    }
    
    return image;
}

int main() {
    auto start = high_resolution_clock::now();

    vector<vector<int>> images = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> ans = floodFill(images,1,1,2);

   for(auto i:ans) {
        for(auto j:i) {
            cout << j << " ";
        } cout << endl;
    }

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}