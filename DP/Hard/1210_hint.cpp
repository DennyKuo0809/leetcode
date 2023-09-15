/* 題目難懂， DP 據說不是最好的解法 ，許多狀況要考慮。 */
class Solution {
public:
    int min_step[2][100][100]; // [0,,]: right, [1,,]: down
    int minimumMoves(vector<vector<int> >& grid) {
        int r = grid.size(), c = grid[0].size();
        const int biggest = 500; // > 100 + 100

        /* Initialize */
        min_step[0][0][0] = 0;
        min_step[1][0][0] = (grid[1][1] || grid[1][0])? biggest : 1; // rotate

        /* DP (tail position )*/
        for(int i = 0 ; i < r ; i ++){
            for(int j = 0 ; j < c ; j ++){
                /* Skip if obstacle or start */
        				if(i == j && j == 0){
        					continue;
        				}

                if(grid[i][j]) {
                    min_step[0][i][j] = min_step[1][i][j] = biggest;
                    continue;
                }

                /* Head to right */
                if(j == c-1 || grid[i][j+1]) min_step[0][i][j] = biggest;
                else { 
        					int from_left = (j == 0)? biggest : min_step[0][i][j-1];
        					int from_up = (i == 0)? biggest : min_step[0][i-1][j];
        					min_step[0][i][j] = 1 + min(from_left, from_up);
        				}
                
				        /* Head to down */
                if(i == r-1 || grid[i+1][j]) min_step[1][i][j] = biggest;
                else {
        					int from_left = (j == 0)? biggest : min_step[1][i][j-1];
        					int from_up = (i == 0)? biggest : min_step[1][i-1][j];
        					min_step[1][i][j] = 1 + min(from_left, from_up);
        				}
                
				        /* Rotate */
                if(i < r-1 && j < c-1 && !grid[i+1][j+1]){
                    int right = min_step[0][i][j], down = min_step[1][i][j];
                    min_step[0][i][j] = (right == biggest)? biggest: min(down + 1, right);
                    min_step[1][i][j] = (down == biggest)? biggest : min(down, right + 1);
                }
            }
        }

        return (min_step[0][r-1][c-2] < biggest)? min_step[0][r-1][c-2]: (-1);
        
    }
};
