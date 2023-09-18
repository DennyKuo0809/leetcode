/* Refer to 221. Maximal Square */
/* Calculate maximal square side length at each element */
/* When the side length of an element is n, there should be n new squares. */

class Solution {
public:
    int len[300][300];
    int top[300];
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i = 0 ; i < matrix.size() ; i ++){
            int left = 0;
            for(int j = 0 ; j < matrix[0].size() ; j ++){
                if(matrix[i][j]){
                    if(i && j && matrix[i-1][j-1]){
                        len[i][j] = 1 + min(
                            len[i-1][j-1],
                            min(top[j], left)
                        );
                    }
                    else len[i][j] = 1;
                    top[j] ++;
                    left ++;
                    ans += len[i][j];
                }
                else{
                    top[j] = left = len[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
