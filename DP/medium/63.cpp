class Solution {
public:
    long long int W[100][100];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();

        bool non_obstacle = true;
        for(int i = 0 ; i < r ; i ++) {
            if(obstacleGrid[i][0]) non_obstacle = false;
            W[i][0] = int(non_obstacle);
        }

        non_obstacle = true;
        for(int j = 0 ; j < c ; j ++) {
            if(obstacleGrid[0][j]) non_obstacle = false;
            W[0][j] = int(non_obstacle);
        }

        long long int from_left, from_up;
        for(int i = 1 ; i < r ; i ++){
            for(int j = 1 ; j < c ; j ++){
                W[i][j] = (obstacleGrid[i][j])? 0 : (W[i-1][j] + W[i][j-1]);
            }
        }
        return W[r-1][c-1];
    }
};
