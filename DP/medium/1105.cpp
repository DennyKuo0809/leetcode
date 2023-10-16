class Solution {
public:
    int min_height[1000];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        min_height[0] = books[0][1];
        for(int i = 1 ; i < books.size() ; i ++){
            int th = books[i][0];
            int max_height = books[i][1];
            min_height[i] = books[i][1] + min_height[i-1];
            for(int j = i-1 ; j >= 0 ; j --){
                th += books[j][0];
                if(th <= shelfWidth){
                    max_height = max(max_height, books[j][1]);
                    int new_height = (j == 0)? max_height : (max_height + min_height[j-1]);
                    min_height[i] = min(min_height[i], new_height);
                }
            }
        }
        return min_height[books.size() - 1];
    }
};
