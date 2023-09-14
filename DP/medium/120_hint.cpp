/* O(n) space */
class Solution {
public:
    int min_sum[200];
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];
        int res = 2147483647;
        min_sum[0] = triangle[0][0];
        for(int i = 1 ; i < triangle.size() ; i ++){
            min_sum[i] = min_sum[i-1] + triangle[i][i];
            if(i == triangle.size()-1) res = min_sum[i];
            for(int j = i-1 ; j >= 0 ; j --){
                min_sum[j] = triangle[i][j] + min(
                    min_sum[j], 
                    (j != 0)? min_sum[j-1] : min_sum[j]
                );
                if(i == triangle.size()-1) res = min(res, min_sum[j]);
            }
        }
        return res;
    }
};
