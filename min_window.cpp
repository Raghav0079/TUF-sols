#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string minWindow(string s , string t){
        int minLen = INT_MAX;
        
        int sIndex = -1;

        for(int i=0 ; i < s.size() ; i++){
            int hash[256] = {0};
            for(char c : t){
                hash[c]++;
            }
            int count = 0;

            for(int j=i ; j < s.size() ; j++){
                if(hash[s[j]] > 0){
                    count++;
                }
                hash[s[j]]--;
                if(count == t.size()){
                    if(minLen > j-i+1){
                        minLen = j-i+1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }
        return (sIndex == -1) ? "" : s.substr(sIndex , minLen);

    }
};


int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution obj;
    cout << obj.minWindow(s , t) << endl;
    return 0;
}