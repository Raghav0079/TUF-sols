class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0,s,path,res);
        return res;
    }

    void dfs(int index , string s , vector<string> &path , vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return ;
        }
        for(int i=index ; i<s.size() ; i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index, i - index + 1));
                // Recur for the remaining substring
                dfs(i + 1, s, path, res);
                // Backtrack: remove the last added substring
                path.pop_back();
            }
        }

    }

    bool isPalindrome(string s, int start, int end) {
        // Check if the substring s[start..end] is a palindrome
        while (start <= end) {
            // If characters do not match, it's not a palindrome
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }


};
