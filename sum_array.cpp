#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int sum(int arr[], int n) {
        int ans = 0; 
        for(int i =0 ; i<n ; i++){
            ans  =ans + arr[i];

        } 
        return ans ;
	  
	}
};