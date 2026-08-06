#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int maxProduct(vector<int>& nums) {
	    int n = nums.size();
	    
	    int ans = INT_MIN; // to store the answer
	    
	    // Indices to store the prefix and suffix multiplication
        int prefix = 1, suffix = 1;
        
        // Iterate on the elements of the given array
        for(int i=0; i < n; i++) {
            
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            
            // update the prefix and suffix multiplication
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            
            // store the maximum as the answer
            ans = max(ans, max(prefix, suffix));
        }
        
        // return the result
        return ans;
	}
};
