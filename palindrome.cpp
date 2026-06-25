#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        int copy=n;
        int revNum=0;

        while(n>0){
            int lastDigit = n%10;
            revNum=(revNum*10) + lastDigit;
            n=n/10;
        }
        if(revNum == copy) return true;
        return false;
    }
};

int main()
{
    int n = 1232;
    
    /* Creating and instance of 
    Solution class */
    Solution sol; 
    
    // Function call to check if n is a palindrome
    bool ans = sol.isPalindrome(n);
    
    if(ans) cout << "The given number is a palindrome";
    else cout << "The given number is not a palindrome";
    
    return 0;
}