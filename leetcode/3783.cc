/* 3783: https://leetcode.com/problems/mirror-distance-of-an-integer/description/ */
class Solution {
public:
    int mirrorDistance(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        int b = stoi(str);

        return abs(n - b);
    }
};
