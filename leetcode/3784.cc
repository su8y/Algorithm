/* 3784: https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/ */
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long sm[26];
        for(int i=0;i<s.size();i++){
            sm[s[i]-'a'] += cost[i];
        }
        set<char> st(s.begin(), s.end());
        vector<char> v(st.begin(), st.end());
        
        sort(v.begin(), v.end(), [&](char a, char b){
            return sm[a-'a'] < sm[b-'a'];
        });

        long long answer = 0;

        for(int i=0;i<v.size()-1;i++){
            answer += sm[v[i]-'a'];
        }

        return answer;
    }
};
