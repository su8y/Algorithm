class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for (int i=0; i<s.size(); i++) {
            if (st.empty() || !IsMatch(st.top(), s[i])) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        
        return st.empty();
    }
private:
    bool IsMatch(char a, char b) {
        if (a == '(' && b == ')') return true;
        if (a == '[' && b == ']') return true;
        if (a == '{' && b == '}') return true;
        return false;
    }
};
