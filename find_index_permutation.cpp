class Solution {
    const int M = 1000000007;

    int mul(long long x, long long y) {
        return (x * y) % M;
    }

    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void update(vector<int> &v, int x) {
        for (; x < v.size(); x += lowbit(x)) {
            v[x]++;
        }
    }

    int query(const vector<int> &v, int x) {
        int r = 0;
        for (; x; x -= lowbit(x)) {
            r += v[x];
        }
        return r;
    }

public:

    int getPermutationIndex(vector<int>& perm) {
        const int n = perm.size();

        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = mul(factorial[i - 1], i);
        }

        vector<int> BIT(n + 1, 0);

        int result = 0;

        for (int i = 0; i < n; ++i) {

            int countUsed = query(BIT, perm[i] - 1);

            int countUnusedSmaller = perm[i] - 1 - countUsed;
            add(result, mul(countUnusedSmaller, factorial[n - 1 - i]));

            update(BIT, perm[i]);
        }

        return result;
    }
};