#include<iostream>
using namespace std;

class Solution {
private:
    /* Function to find whether the
    number is prime or not */
    bool isPrime(int n) {
        
        /* Variable to store the 
        count of divisors of n */
        int count = 0;
        
        // Loop from 1 to square root of n
        for(int i = 1; i <= sqrt(n); ++i) {
            
            // Check if i is a divisor
            if(n % i == 0) {
                // Increment count
                count = count + 1;
                
                /* Check if counterpart divisor
                is different from original divisor */
                if(n % i != i) {
                    
                    // Increment count
                    count = count + 1;
                }
            }
        }
        
        // If count is 2, n is prime
        if(count == 2) return true;
        // Else not prime
        return false;
    }
    
public:
    /* Function to find count
    of primes till n */
    int primeUptoN(int n) {
        
        // Variable to store count
        int count = 0;
        
        // Iterate from 2 to n
        for (int i = 2; i <= n; i++) {
            
            // Check if i is prime
            if (isPrime(i)) count++;
        }
        
        // Return the count
        return count;
    }
};