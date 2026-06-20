#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to print pattern14
    void pattern14(int n) {
        // Outer loop for the number of rows.
        for(int i=0;i<n;i++){
          
            for(char ch = 'A'; ch<='A'+i;ch++){
                cout<<ch;
            }  

            cout<<endl;
        }
    }

};
