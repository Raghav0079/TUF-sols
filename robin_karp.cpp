#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> search(string pat, string txt) {
        int n = pat.length();
        int m = txt.length();
        
        int p = 7, mod = 101;
        int hashPat = 0, hashText = 0;
        int pRight = 1, pLeft = 1;
        
        
        for(int i=0; i < n; i++) {
            hashPat += ((pat[i]-'a'+1) * pRight) % mod;
            hashText += ((txt[i]-'a'+1) * pRight) % mod;
            pRight = (pRight * p) % mod;
        }
        

        vector<int> ans;
        
        for(int i=0; i <= m-n; i++) {
            
            if(hashPat == hashText) {
                
                if(txt.substr(i, n) == pat) ans.push_back(i);
            }
            
           
            hashText = (hashText - ((txt[i] - 'a'+1) * pLeft) % mod + mod) % mod;
            hashText = (hashText + ((txt[i+n] - 'a'+1) * pRight) % mod) % mod;
            hashPat = (hashPat * p) % mod;
            
            
            pLeft = (pLeft * p) % mod;
            pRight = (pRight * p) % mod;
        }
        
        return ans; 
    } 
};

class Main {
    public static void main(String[] args) {
        String txt = "ababcabcababc";
        String pat = "abc";
 
        // Creating an instance of Solution class
        Solution sol = new Solution();
 
        /* Function call to find the starting index
           of all occurrences of pattern in text */
        List<Integer> ans = sol.search(pat, txt);
 
        // Output
        System.out.print("The starting indices of all occurrences of " + pat + " in " + txt + " are: ");
        for (int it : ans) System.out.print(it + " ");
    }
}