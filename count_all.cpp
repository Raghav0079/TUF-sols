#include<iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        if(n ==0) return 1 ;
        int count = 0 ;
        while ( n> 0){
            count = count + 1 ;
            n = n / 10 ;
        }
        return count ; 
    }
};