class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;

        for ( int i=0 ; i < V -1 ; i++){
            for ( auto it : edges){
                int u = it[0]; // node 1
                int v = it[1]; // node 2
                int wt = it[2]; // edge weight

                if ( dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }

            }
        }
        for(auto it : edges) {
            
            int u = it[0]; // node 1
            int v = it[1]; // node 2
            int wt = it[2]; // edge weight
            

            if(dist[u] != 1e9 && 
               dist[u] + wt < dist[v]) {
                   
                // Return {-1}
                return {-1};
            }
        }

        return dist;

	}
};
