#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    
    // adjacency matrix
    int n,m;
    cin >> n >> m;
    int arr[n+1][n+1] = {0};
    for(int i=0; i<m; i++) {
        int v,u;
        cin >> v >> u;
        arr[v][u]=1;
    }
    // matrix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }
}