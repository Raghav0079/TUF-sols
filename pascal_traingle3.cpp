class Solution {
private:
    vector<int> generateRow(int row){
        long long ans =1 ;
        vector<int> ansRow;

        ansRow.push_back(1);

        for(int col =1 ; col<row ; col++){
            ans = ans * (row -col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

public:
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> pascalTriangle;
        
        
        for (int row = 1; row <= n; row++) {
            pascalTriangle.push_back(generateRow(row));
        }

        return pascalTriangle;
        
    }
};