class Solution{	
	public:		
		bool palindromeCheck(string& s){
            return isPalindrome(s,0,s.length() -1);
        }
    private:
        bool isPalindrome(string& s, int left, int right){
            if(left >= right){
                return true;
            }
            if (s[left] != s[right]) {
            return false;
            }
            return isPalindrome(s, left + 1, right - 1);
        }
};