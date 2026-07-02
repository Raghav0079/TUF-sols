class Solution{	
private:
    void reverse(vector<char> & s , int left , int right){
        if(left >= right) return ;
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp ;

        reverse(s,left+1,right-1);
    }



public:		
	vector<char> reverseString(vector<char>& s){
        int left = 0 ;
        int right = s.size() -1 ;
        reverse(s,left,right);
        return s ;
    }
};