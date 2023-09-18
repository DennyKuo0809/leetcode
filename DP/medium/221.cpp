class Solution {
public:
    int len[300][300];
    int top[300];
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int ans = 0;
        for(int i = 0 ; i < r ; i ++ ){
            int left = 0;
            for(int j = 0 ; j < c ; j ++){
                if(matrix[i][j]-'0'){
                    if(i && j && matrix[i-1][j-1] ){
                        len[i][j] = min(len[i-1][j-1], min(left, top[j])) + 1;
                    }
                    else len[i][j] = 1;
                    ans = max(ans, len[i][j]);
                    left ++;
                    top[j] ++;
                }
                else {
                    len[i][j] = 0;
                    left = 0;
                    top[j] = 0;
                }
            }
        }
        return ans * ans;
    }
};
