/* 136:https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=v1pdb9am */
class Solution {
public:
    // XOR
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto e : nums) {
            ans ^= e;
        }
        return ans;
    }
    // set 사용 O(N)이지만 set을 구성하는 log N의 시간 복잡도가 필요하여 N log n 
    // int singleNumber(vector<int>& nums) {
    //     set<int> s;

    //     for(auto e: nums) {
    //         if(s.count(e) == 0) s.insert(e);
    //         else s.erase(e);
    //     }
    //     return *s.begin();
    // }
};
