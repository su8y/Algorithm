/* 119: https://leetcode.com/problems/pascals-triangle-ii/?envType=problem-list-v2&envId=v1pdb9am
2차원 prefixsum
n = 33
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int> metrix = {1,1};
        

        for(int i=2;i<=rowIndex;i++){
            vector<int> tmp;
            tmp.push_back(metrix[0]);
            for(int j=0;j<i-1;j++){
                tmp.push_back(metrix[j] + metrix[j+1]);
            }
            tmp.push_back(metrix[i-1]);
            metrix = tmp;
        }
        return metrix;
    }
};
