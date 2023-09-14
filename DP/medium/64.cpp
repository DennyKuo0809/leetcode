class Solution {
public:
    int min_sum[200][200];
    int minPathSum(vector<vector<int>>& grid) {
        min_sum[0][0] = grid[0][0];
        for(int i = 1 ; i < grid.size() ; i ++){
            min_sum[i][0] = grid[i][0] + min_sum[i-1][0];
        }
        for(int j = 1 ; j < grid[0].size() ; j ++) {
            min_sum[0][j] = grid[0][j] + min_sum[0][j-1];
        }
        for(int i = 1 ; i < grid.size() ; i ++){
            for(int j = 1 ; j < grid[0].size() ; j ++){
                min_sum[i][j] = grid[i][j] + min(min_sum[i][j-1], min_sum[i-1][j]);
            }
        }

        return min_sum[grid.size()-1][grid[0].size()-1];
    } 
};
