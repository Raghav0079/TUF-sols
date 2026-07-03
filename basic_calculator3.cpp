#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    int pos = 0;

    long helper(string& s) {
        stack<long> st;
        long curr = 0;
        char op = '+';
        
        while (pos < s.length()) {
            char ch = s[pos++];
            if (isdigit(ch)) curr = curr * 10 + (ch - '0');
            else if (ch == '(') curr = helper(s);
            
            if (ch == ')' || pos == s.length() || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (op == '+') st.push(curr);
                else if (op == '-') st.push(-curr);
                else if (op == '*') {
                    long top = st.top(); st.pop();
                    st.push(top * curr);
                } else if (op == '/') {
                    long top = st.top(); st.pop();
                    st.push(top / curr);
                }
                op = ch;
                curr = 0;
            }
            if (ch == ')') break;
        }
        long res = 0;
        while (!st.empty()) { res += st.top(); st.pop(); }
        return res;
    }

public:
    int calculate(string s) {
        pos = 0;
        return (int)helper(s);
    }
};
