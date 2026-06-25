class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return -dividend;


        bool isPositive = (dividend >= 0 == divisor >= 0);
        

        long n = labs((long)dividend);
        long d = labs((long)divisor);

        int ans = 0;


        while (n >= d) {
            int count = 0;


            while (n >= (d << (count + 1))) {
                count++;
            }
            
            ans += (1 << count);
            n -= (d << count);
        }


        if (ans == INT_MIN && isPositive) return INT_MAX; 

        return isPositive ? ans : -ans;
    }
};