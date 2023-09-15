class Solution {
public:
    int min_sum[100][100];
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for(int j = 0 ; j < c ; j ++){
            min_sum[0][j] = matrix[0][j];
        }

        int le, ce, ri;
        int res = 2147483647;
        for(int i = 1 ; i < r ; i ++ ){
            for(int j = 0 ; j < c ; j ++){
                min_sum[i][j] = min_sum[i-1][j];
                if(j != 0) min_sum[i][j] = min(min_sum[i][j], min_sum[i-1][j-1]);
                if(j != c-1) min_sum[i][j] = min(min_sum[i][j], min_sum[i-1][j+1]);
                min_sum[i][j] += matrix[i][j];
            }
        }

        for(int j = 0 ; j < c ; j ++) res = min(res, min_sum[r-1][j]);

        return res;
    }
};
