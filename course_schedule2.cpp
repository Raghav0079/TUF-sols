class Solution {
private:
    vector<int> topoSort( int V , vector<int> adj[]){
        vector<int> inDegree(V, 0);
	    
		for (int i = 0; i < V; i++) {
		    
			for(auto it : adj[i]) {
			    // Update the in-degree
			    inDegree[it]++;
			}
		}

        vector<int> ans;
        queue<int> q;
        for(int i=0; i<V; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }

        while( !q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for( auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
  public: 
    vector < int > findOrder(int N, vector < vector < int >> arr) {
        vector<int> adj[N];

        for(auto it : arr) {
            int u = it[0];
            int v = it[1];
            
            // Add the edge v-> u
            adj[v].push_back(u);
        }

        vector<int> topo = topoSort(N ,adj);
        if( topo.size() < N) return{};
        return topo;
   
  }
};

int main() {
    
    int N = 4;
    vector<vector<int>> arr = {
         {1,0},
         {2,1},
         {3,2}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine order
	of tasks to finish all tasks */
    vector<int> ans = sol.findOrder(N, arr);
    
    // Output
    cout << "The order to perform tasks is:\n";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}