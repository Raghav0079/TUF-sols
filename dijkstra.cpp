#include <bits/stdc++.h>
using namespace std;

#define P pair<int , int>

class Solution{

public : 

    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, S});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    } 
};

int main(){
    int V = 2 , S =0;
    vector< vector<int>> edges = {
        {0,1,9}
    };

    Solution sol;
    vector<int> ans = sol.dijkstra(V, edges, S);
    cout << " the shortest distance of nodes from the source node is :";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

