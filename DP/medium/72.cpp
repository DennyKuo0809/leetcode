class Solution {
public:
    int dis[501][501];
    int minDistance(string word1, string word2) {
        dis[0][0] = 0;
        int l1 = word1.length(), l2 = word2.length();
        for(int i = 0 ; i < l2 ; i ++) dis[i+1][0] = i+1;
        for(int j = 0 ; j < l1 ; j ++) dis[0][j+1] = j+1;
        for(int i = 0 ; i < l2 ; i ++){
            for(int j = 0 ; j < l1 ; j ++){
                if(word1[j] == word2[i]) dis[i+1][j+1] = dis[i][j];
                else{
                    dis[i+1][j+1] = 1+ min(dis[i][j], min(dis[i+1][j], dis[i][j+1]));
                }
            }
        }
        return dis[l2][l1];
    }
};
