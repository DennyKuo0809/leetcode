class Solution {
public:
    int left[200][200];
    // left[i][j] = (On row i, consecutive 1s with rightmost column j)
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        for(int i = 0 ; i < r ; i ++){
            for(int j = 0 ; j < c ; j ++){
                if(matrix[i][j] == '0') left[i][j] = 0;
                else if(j) left[i][j] = left[i][j-1] + 1;
                else left[i][j] = 1;
            }
        }

        int res = 0;
        const int INF = 2147483647;
        // calculate the area with rightmost column on j
        // and top row r1, bottom row r2
        for(int r1 = 0 ; r1 < r ; r1 ++){
            for(int j = 0 ; j < c ; j ++){
                int min_len = INF;
                for(int r2 = r1 ; r2 < r ; r2 ++){
                    min_len = min(min_len, left[r2][j]);
                    if(!min_len) break;
                    res = max(res, min_len * (r2 - r1 + 1));
                }
            }
        }
        return res;
    }
};
