class Solution {
public:
    vector<string> expand(string s) {
        vector<vector<string>> groups;
        int i=0 , n=s.length();

        while(i<n){
            if(s[i] == '{'){
                i++;
                string temp;

                while(i<n && s[i] != '}'){
                    temp += s[i++];

                }
                vector<string> group;
                stringstream ss(temp);
                string part;

                while(getline(ss,part,',')){
                    group.push_back(part);
                }
                sort(group.begin() , group.end());
                groups.push_back(group);
                i++;
            }else{
                groups.push_back({string(1, s[i++])});
            }
        }
        vector<string> result;
        backtrack(groups, 0, "", result); 
        return result;
        
    }


private:
    void backtrack(const vector<vector<string>>& groups, 
    int idx, string current, vector<string>& result){
        if(idx == groups.size()){
            result.push_back(current);
            return;
        }
        for (const string& option : groups[idx]) {
            backtrack(groups, idx + 1, current + option, result);
        }
    }

};