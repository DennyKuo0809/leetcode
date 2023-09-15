class Solution {
public:
    int min_heal[200][200];
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size(), c = dungeon[0].size();
        min_heal[r-1][c-1] = (dungeon[r-1][c-1] < 0)? (1 - dungeon[r-1][c-1]) : 1;
        for(int i = r-2 ; i >= 0 ; i --){
            if(dungeon[i][c-1] < 0) min_heal[i][c-1] = min_heal[i+1][c-1] - dungeon[i][c-1];
            else if(dungeon[i][c-1] >= min_heal[i+1][c-1]) min_heal[i][c-1] = 1;
            else min_heal[i][c-1] = min_heal[i+1][c-1] - dungeon[i][c-1];
        }

        for(int j = c-2 ; j >= 0 ; j --){
            if(dungeon[r-1][j] < 0) min_heal[r-1][j] = min_heal[r-1][j+1] - dungeon[r-1][j];
            else if(dungeon[r-1][j] >= min_heal[r-1][j+1]) min_heal[r-1][j] = 1;
            else min_heal[r-1][j] = min_heal[r-1][j+1] - dungeon[r-1][j];
        }

        for(int i = r-2 ; i >= 0 ; i --){
            for(int j = c-2 ; j >= 0 ; j --){
                int next = min(min_heal[i+1][j], min_heal[i][j+1]);
                if(dungeon[i][j] < 0) min_heal[i][j] = next - dungeon[i][j];
                else if(dungeon[i][j] >= next) min_heal[i][j] = 1;
                else min_heal[i][j] = next - dungeon[i][j];
            }
        }

        return min_heal[0][0];
    }
};
