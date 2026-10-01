#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //Function to solve the problem using tabulation
    int func(vector<int> &nums){
        int n = nums.size();
        int prev = nums[0];   
        int prev2 = 0;       
    
        for (int i = 1; i < n; i++) {
            // Maximum sum if we pick current element
            int pick = nums[i];  
            
            if (i > 1){
                //Add the maximum sum two elements ago
                pick += prev2;  
            }
            // Maximum sum if we don't pick current element
            int nonPick = 0 + prev;  
            
            // Maximum at the current element
            int cur_i = max(pick, nonPick); 
            
            prev2 = prev;   
            prev = cur_i;    
        }
        // Return the maximum sum
        return prev;  
    }
public:
    //Function to find the maximum money robber can rob
    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> arr1;
        vector<int> arr2;
       
        //If array has only one element, return that
        if(n==1)
           return money[0];
        
        for(int i=0; i<n; i++){
            /*Store every element in 
            arr1 except the last element*/
            if(i!=n-1) arr1.push_back(money[i]);
            
            /*Store every element in 
            arr2 except the first element*/
            if(i!=0) arr2.push_back(money[i]);
        }
        int ans1 = func(arr1);
        
        int ans2 = func(arr2);
    
        //Return the maximum of an1 and ans2
        return max(ans1,ans2);
    }
};

int main(){
    vector<int> arr{1,5,1,2,6};
 
    //Create an  instance of Solution class
    Solution sol;
    
    //Print the solution
    cout<<sol.houseRobber(arr);
}