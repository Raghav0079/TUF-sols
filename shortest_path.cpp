#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    // Function to perform BFS traversal
    void bfs(int src, vector<int> adj[],
             vector<int> &dist) {
        
        // Distance of source node from itself is zero
        dist[src] = 0; 
        
        // Queue to facilitate BFS traversal
        queue<int> q;
        
        // Adding source node to queue
        q.push(src); 
        
        // Until the queue is empty
        while(!q.empty()) {
            
            // Get the node from queue
            int node = q.front(); 
            q.pop(); 
            
            // Traverse all its neighbors
            for(auto adjNode : adj[node]) {
                
                // If a shorter distance is found
                if(dist[node] + 1 < dist[adjNode]) {
                    
                    // Update the distance
                    dist[adjNode] = 1 + dist[node]; 
                    
                    // Add the node to the queue
                    q.push(adjNode); 
                }
            }
        }
    }
    
public:

    /* Function to get the shortest path 
    for every node from source node 0 */
    vector<int> shortestPath(vector<vector<int>>& edges, 
                             int N, int M){

        // To store the graph
        vector<int> adj[N];
        
        // Add edges to the graph
        for(auto it : edges) {
            int u = it[0]; // first node
            int v = it[1]; // second node
            
            // Add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Distance array to store the shortest paths
        vector <int> dist(N, 1e9);
        
        // Start the BFS traversal from source node
        bfs(0, adj, dist);
        
        /* If a node is unreachable, 
        updating its distance to -1 */
        for(int i = 0; i < N; i++) {
            if (dist[i] == 1e9) 
                dist[i] = -1;
        }
        
        // Return the result
        return dist;
    }
};

int main() {
    
    int N = 9, M = 10;
    vector<vector<int>> edges = {
        {0,1}, {0,3}, {3,4}, 
        {4,5}, {5,6}, {1,2}, 
        {2,6}, {6,7}, {7,8}, {6,8}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine order of 
	letters based on alien dictionary */
    vector<int> ans = sol.shortestPath(edges, N, M);
    
    // Output
    cout << "The shortest distance of every node from source node is:\n";
    for(int i=0; i < N; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}