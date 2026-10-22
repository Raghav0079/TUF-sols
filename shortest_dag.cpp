class Solution {
private:

    // Function to perform DFS traversal
    void topoSort(int node, vector <pair<int,int>> adj[],
                  vector<bool> &vis, stack <int> & st) {
                
        // Mark the node as visited 
        vis[node] = 1;
        
        // Traverse all the neighbors
        for (auto it: adj[node]) {
            
            // Get the node
            int v = it.first;
            
            // If not visited, recursively perform DFS.
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        
        /* Add the current node to stack 
        once all the nodes connected to it 
        have been processed */
        st.push(node);
    }
    
public:

    /* Function to get the shortest path 
    for every node from source node 0 */
    vector<int> shortestPath(int N, int M, 
            vector<vector<int>> &edges) {

        // To store the graph
        vector <pair<int,int>> adj[N];
        
        // Add edges to the graph
        for (int i = 0; i < M; i++) {
            int u = edges[i][0]; // node 1
            int v = edges[i][1]; // node 2
            int wt = edges[i][2]; // edge weight
            
            // Add the weighted edge 
            adj[u].push_back({v, wt}); 
        }
        
        
        // Visited array
        vector<bool> vis(N, false);
        
        /* Stack to facilitate topological 
        sorting using DFS traversal */
        stack <int> st;
        
        // Get the topological ordering
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
              topoSort(i, adj, vis, st);
            }
        }
        
        // Distance array to store the shortest paths
        vector <int> dist(N, 1e9);
        
        // Distance of source node to itself is zero
        dist[0] = 0;
        
        // Until the stack is not empty
        while (!st.empty()) {
            
            // Get the node from top of stack
            int node = st.top();
            st.pop();
            
            // Update the distances of adjacent nodes
            for (auto it: adj[node]) {
                int v = it.first; // adjacent node
                int wt = it.second; // edge weight
                
                /* Relaxing the edge, i.e., if a 
                shorter path is found, update its
                distance to new shorter distance*/
                if (dist[node] + wt < dist[v]) {
                    dist[v] = wt + dist[node];
                }
            }
        }
        
        /* If a node is unreachable, 
        updating its distance to -1 */
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) 
                dist[i] = -1;
        }
        
        // Return the result
        return dist;
    }
};