#include<iostream>
using namespace std;

class Solution {
private:
    int countDigit(int n){
        if (n==0) return 1;
        int count = log10(n) + 1;
        return count ;
    }

public:
    bool isArmstrong(int n) {
        int count = countDigit(n);
        long long sum = 0;
        int copy = n;

        while(n>0){
            int lastDigit = n%10 ;
            sum += pow(lastDigit,count);
            n = n / 10;
        } 
        if (sum == copy) return true ;
        return false ;
    }
};