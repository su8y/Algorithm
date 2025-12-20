/* 169: https://leetcode.com/problems/majority-element/description/ */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int pin = n / 2;
        unordered_map<int, int> mp;

        for (auto e : nums) {
            mp[e]++;
            if(mp[e] > pin) return e;
        }

        return -1;
    }
};
