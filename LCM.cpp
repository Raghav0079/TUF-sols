#include<iostream>
using namespace std;

class Solution {
private:
    int GCD(int n1 , int n2){
        while(n1>0 && n2>0){
            if(n1>n2){
                n1=n1%n2;
            }
            else{
                n2=n2%n1;
            }
        }
        if(n1==0) return n2;
        return n1;
    }


public:
    int LCM(int n1,int n2) {
        int gcd = GCD(n1,n2);
        int lcm = (n1*n2) / gcd;
        return lcm;

    }
};