class DisjointSet {

    int[] rank, parent, size;

    // Constructor
    DisjointSet(int n) {
        rank = new int[n + 1];
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
}

// Solution class
class Solution {
    // DelRow and delCol for neighbors
    int[] delRow = {-1, 0, 1, 0};
    int[] delCol = {0, 1, 0, -1};

    boolean isValid(int i, int j, int n, int m) {
        
        // Return false if cell is invalid
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= m) return false;
        
        // Return true if cell is valid
        return true;
    }

    public List<Integer> numOfIslands(int n, int m, int[][] A) {
        
        // Disjoint set Data structure
        DisjointSet ds = new DisjointSet(n * m);

        // Visited array
        int[][] vis = new int[n][m];
        for (int[] row : vis) Arrays.fill(row, 0);

        // To store the count of islands
        int cnt = 0;

        // To store the result
        List<Integer> ans = new ArrayList<>();

        // Perform each operation
        for (int[] it : A) {
            int row = it[0]; // Row
            int col = it[1]; // Column

            if (vis[row][col] == 1) {
                ans.add(cnt);
                continue;
            }

            // Make the cell as land
            vis[row][col] = 1;

            cnt++;

            // Check all the neighbors
            for (int ind = 0; ind < 4; ind++) {
                // Get the coordinates of cell
                int newRow = row + delRow[ind];
                int newCol = col + delCol[ind];

                // If the cell is a valid land cell
                if (isValid(newRow, newCol, n, m) && 
                    vis[newRow][newCol] == 1) {
                        
                    // Get the node and adjacent node number
                    int nodeNo = row * m + col;
                    int adjNodeNo = newRow * m + newCol;

                    // If not already connected, perform the union
                    if (ds.findUPar(nodeNo) != 
                        ds.findUPar(adjNodeNo)) {
                        // Decrement count
                        cnt--;

                        // Perform the union
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }


            ans.add(cnt);
        }

        // Return the result
        return ans;
    }
}