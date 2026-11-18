
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithXorK(vector<int>& nums, int k)
    {
        int n = nums.size(); 
        int xr = 0;
        map<int, int> mpp; 
        // setting the value of 0.
        mpp[xr]++; 
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            xr = xr ^ nums[i];
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
            
        }
        return cnt;
    }
};
