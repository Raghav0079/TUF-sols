class Solution {
private:
    
    // Function to perform DFS traversal
    bool dfs(int i, vector<int> adj[], 
            vector<bool> &visited, 
            int prev) {
                
        // Mark the node as visited
        visited[i] = true;
        
        // Traverse all the neighbors
        for(auto node : adj[i]) {
            
            // If not visited
            if(!visited[node]) {
                
                /* Recursively perform DFS, and 
                return true if cycle is found */
                if(dfs(node, adj, visited, i)) {
                    return true;
                }
            }
            
            /* Else if it is visited with some 
            different parent a cycle is detected */
            else if(node != prev){
                return true;
            }
            
        }
        
        // Return false if no cycle is detected
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        // Visited array
        vector<bool> visited(V, false);
        
        // Start Traversal from every unvisited node
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                
                if(dfs(i, adj, visited, -1)) {
                    return true;
                }
            }
        }
        
        // Return false if no cycle is detected
        return false;
    }
};