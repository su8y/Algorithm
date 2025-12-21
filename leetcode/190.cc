/* 190: https://leetcode.com/problems/reverse-bits/ */
class Solution {
public:
    int reverseBits(int n) {
       int answer = 0; 
       for(int i=0;i<32;i++) {
            int on = 1 << i;
            if ((n & on) == on) {
                answer |= (1 << (31 - i));
            }
       }
       return answer;
    }
};
