#include<bits/stdc++.h>
using namespace std;

int Count_Paths(vector<vector<int>> &maze, vector<vector<bool>> &visited, int i, int j) {
    
    if(i<0 || i>=maze.size() || j >= maze[0].size() || j < 0) {
        return 0;
    }

    if(maze[i][j] == 0 || visited[i][j] == true) {
        return 0;
    } 

    if(i == maze.size()-1 && j == maze[0].size()-1) {
        return 1;
    }

    // mark visied 
    visited[i][j] = true;

    // now move
    int up = Count_Paths(maze,visited,i-1,j);
    // down
    int down = Count_Paths(maze,visited,i+1,j);
    // left
    int left = Count_Paths(maze,visited,i,j-1);
    // right
    int right = Count_Paths(maze,visited,i,j+1);

    visited[i][j] = false;

    return up+down+left+right;

}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    vector<vector<bool>> visited(maze.size(),vector<bool> (maze[0].size(), false));
    cout << Count_Paths(maze,visited, 0, 0) << endl;
}