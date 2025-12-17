/* 121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=v1pdb9am */
class Solution {
public:
    // O(N)
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int mx = 0;
        for(int i=1;i<prices.size();i++) {
            if (prices[i] < buy) buy = prices[i];
            else if (prices[i] - buy > mx) mx = prices[i] - buy;
        }
        return mx;
    }
    // O(N^2)
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int mx = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++) {
    //             if (prices[j] - prices[i] > mx) mx = prices[j] - prices[i];
    //         }
    //     }
    //     return mx;
    // }
};
