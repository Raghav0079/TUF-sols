class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);  
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }


    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }
};

class Solution {
public:

    int subarraysWithMoreOnesThanZeros(vector<int>& nums) {
        const int MOD = 1e9 + 7;  
        int n = nums.size();

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = (nums[i] == 1) ? 1 : -1;  

        vector<long long> prefix(n + 1, 0); 
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];  

        vector<long long> sorted_prefix = prefix;
        sort(sorted_prefix.begin(), sorted_prefix.end());
        sorted_prefix.erase(unique(sorted_prefix.begin(), sorted_prefix.end()), sorted_prefix.end());


        auto getIndex = [&](long long x) {
            return int(lower_bound(sorted_prefix.begin(), sorted_prefix.end(), x) - sorted_prefix.begin()) + 1;
        };

        FenwickTree fenwicks((int)sorted_prefix.size());  
        int result = 0;

        fenwicks.update(getIndex(0), 1);


        for (int i = 1; i <= n; ++i) {
            int idx = getIndex(prefix[i]);  

            int count_smaller = fenwicks.query(idx - 1);
            result = (result + count_smaller) % MOD;  
            fenwicks.update(idx, 1);  
        }

        return result;  
    }
};