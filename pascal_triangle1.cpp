class Solution {
public:
    int pascalTriangleI(int r, int c) {
        // Pascal's triangle positions are calculated using (r-1)C(c-1)
        return nCr(r - 1, c - 1);
    }

private:
    int nCr(int n, int r) {
        // Base cases: nC0 = 1, and nCn = 1
        if (r == 0 || r == n) return 1;
        
        // Symmetry property: nCr = nC(n-r)
        if (r > n - r) r = n - r;
        
        long long res = 1; // Use long long to prevent integer overflow during multiplication

        for (int i = 0; i < r; i++) { // Fixed the "i , r" syntax error to "i < r"
            res = res * (n - i);
            res = res / (i + 1);
        }
        
        return (int)res;
    }
};