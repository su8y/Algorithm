/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        short tmpLen =0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == ' ') {
                if(tmpLen != 0) {
                    len = tmpLen;
                }
                tmpLen = 0;
            } else { 
                tmpLen++;
            }
        }
        
        if(tmpLen != 0) {
            len = tmpLen;
        }
        return len;
    }
};
// @lc code=end

