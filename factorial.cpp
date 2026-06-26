
#include<iostream>
using namespace std;


class Solution {
public:
    int factorial(int n) {
        if ( n==0) return 1 ;

        int fact = 1 ;
        int i ;

        for ( i=1 ; i<=n ; i++){
            fact = fact *i ;

        }
        return fact;
    }
};
