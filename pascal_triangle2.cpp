#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    vector<int> pascalTriangleII(int r) {
        vector<int> ans(r);
        ans[0] = 1;
        
        
        int n = r - 1; 
        
        for (int i = 1; i < r; i++) {
            
            long long next_val = ((long long)ans[i - 1] * (n - i + 1)) / i;
            ans[i] = (int)next_val;
        }
        return ans;
    }
};