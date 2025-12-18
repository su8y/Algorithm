/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 * lead, trailing space가 없고 single space 제약조건 이기 때문에 ss 로 간단하게 split
 */

// @lc code=start
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> answer;
        unordered_map<string, int> mp;
        
        SplitSpaceAndInsertMap(s1, mp);
        SplitSpaceAndInsertMap(s2, mp);
        
        for (auto e: mp) {
            cout << e.first << " " << e.second << endl;
            if(e.second == 1)  {
                answer.push_back(e.first);
                
            }
        }
        return answer;
    }
private:
    void SplitSpaceAndInsertMap(const string &s, unordered_map<string, int> &mp) {
        string ss;
        for(nt i=0;i<s.size();i++){
            if (s[i] == ' ') {
                if (ss.size() == 0) continue;
                mp[ss]++;
                ss = "";
            } else {
                ss += s[i];
            }
        }

        if (ss.size() != 0) {
            mp[ss]++;
        }i
    }

};
// @lc code=end

