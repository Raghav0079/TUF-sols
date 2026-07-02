#include<iostream>
using namespace std;


class Solution{	
	public:
		long long int factorial(int n){
            if ( n <= 1) return 1;
            return n * factorial(n-1);

        }
};