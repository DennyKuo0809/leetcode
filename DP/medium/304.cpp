class NumMatrix {
public:
    int sum[200][200];
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for(int i = 0 ; i < r ; i ++){
            for(int j = 0 ; j < c ; j ++){
                if(i && j) sum[i][j] = matrix[i][j] + (sum[i][j-1] - sum[i-1][j-1]) + sum[i-1][j];
                else if(i) sum[i][j] = matrix[i][j] + sum[i-1][j];
                else if(j) sum[i][j] = matrix[i][j] + sum[i][j-1];
                else sum[i][j] = matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 && col1){
            return (sum[row2][col2] - sum[row1-1][col2] - sum[row2][col1-1] + sum[row1-1][col1-1]);
        }
        else if(row1) return sum[row2][col2] - sum[row1-1][col2];
        else if(col1) return sum[row2][col2] - sum[row2][col1-1];
        else return sum[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
