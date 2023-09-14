class Solution {
public:
    int W[100][100];
    int uniquePaths(int m, int n) {
        for(int i = 0 ; i < m ; i ++) W[i][0] = 1;
        for(int j = 0 ; j < n ; j ++) W[0][j] = 1;
        for(int i = 1 ; i < m ; i ++){
            for(int j = 1 ; j < n ; j ++){
                W[i][j] = W[i-1][j] + W[i][j-1];
            }
        }
        return W[m-1][n-1];
    }
};
