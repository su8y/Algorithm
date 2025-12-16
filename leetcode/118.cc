/* 118. https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // i+1, j i+1, j+1 
        vector<vector<int>> vv;
        for(int i=0;i<numRows;i++){
            vv.push_back(vector<int>(i+1, 0));
        }
        vv[0][0] = 1;

        for(int i=0;i<numRows - 1;i++) {
            for(int j=0;j<=i;j++){
                for(int k=0;k<2;k++){
                    if(j+1 >= numRows) continue;
                    vv[i+1][j+k] += vv[i][j];
                }
            }
        }
        return vv;

    }
};
