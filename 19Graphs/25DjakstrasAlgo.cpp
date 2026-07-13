#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// we use min heap - priority queue

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

vector<int> Djakstra(int V, vector<vector<pair<int,int>>>&adj, int src) {
    vector<int> dis(V+1, INT_MAX);
    dis[src]=0;
    minHeap.push({dis[src], src}); // dis,src

    while(!minHeap.empty()) {
        auto top = minHeap.top();
        minHeap.pop();

        for(auto ng:adj[top.second]) {
            if(top.first + ng.second < dis[ng.first]) {
                dis[ng.first] = top.first + ng.second;
            }
            minHeap.push({dis[ng.first], ng.first});
        }
    }

    return dis;
}

vector<int> Djakstra_Set( int V, vector<vector<pair<int,int>>> adj, int src) {
    set<pair<int,int>> st;
    vector<int> dis(V+1,INT_MAX);

    dis[src] = 0;
    st.insert({dis[src],src}); // {dis,node}

    while(!st.empty()) {
        auto item = *st.begin();   // Copy the pair
        st.erase(st.begin());

        int dist = item.first;
        int node = item.second;

        for (auto ng : adj[node]) {
            if (dist + ng.second < dis[ng.first]) {

                if (dis[ng.first] != INT_MAX)
                    st.erase({dis[ng.first], ng.first});

                dis[ng.first] = dist + ng.second;
                st.insert({dis[ng.first], ng.first});
            }
        }
    }

    return dis;
}

int main() {
    auto start = high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v,x});
    }

    // vector<int> ans = Djakstra(n,adj,1);
    vector<int> ans = Djakstra_Set(n,adj,1);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    } cout << endl;

    auto end = high_resolution_clock::now();
    cout << "Time taken: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    return 0;
}
/*
6 8
1 2 2
1 4 1
2 3 3
4 2 2
4 5 4
5 3 1
5 6 2
3 6 5
*/