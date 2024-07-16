/* Approach 1 */
/* O(n^2), not a good one */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size();
        if(l == 1) return 1;

        vector<int> n(l, 0);
        int cnt = l;

        if(ratings[0] <= ratings[1]) {
            n[0] = 1;
            cnt --;
        }
        else n[0] = -1;
        if(ratings[l-1] <= ratings[l-2]) {
            n[l-1] = 1;
            cnt --;
        }
        else n[l-1] = 2-l;
        for(int i = 1 ; i < l-1 ; i ++){
            if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) {
                n[i] = 1;
                cnt --;
            }
            else if(ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1]){
                n[i] = 1;
                cnt --;
            }
            else if(ratings[i] > ratings[i+1]) {
                if(n[i+1] > 0){
                    n[i] = n[i+1] + 1;
                    cnt --;
                }
                else n[i] = -1-i;
            }
            else {
                if(n[i-1] > 0){
                    n[i] = n[i-1] + 1;
                    cnt --;
                }
                else n[i] = 1-i;
            }
        }
        
        while(cnt){
            for(int i = 0 ; i < l ; i ++){
                if(n[i] <= 0 && n[-n[i]] > 0){
                    n[i] = n[-n[i]] + 1;
                    cnt --;
                }
            }
        }
        for(int i = 1 ; i < l-1 ; i ++){
            if(ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1])
                n[i] = max(n[i-1], n[i+1]) + 1;
        }

        int ans = 0;
        for(int i = 0 ; i < l ; i ++){
            ans += n[i];
        }

        return ans;

    }
};


/* Approach 2 */
/* Two pass, O(n) with O(n) space */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size();
        if(l == 1) return 1;
        vector<int> candies(l, 1);

        for(int i = 1 ; i < l ; i ++){
            if(ratings[i] > ratings[i-1]) candies[i] = max(candies[i], candies[i-1] + 1);
        }

        for(int i = l-2 ; i >= 0 ; i --){
            if(ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
        }

        int ans = 0;
        for(int i = 0 ; i < l ; i ++) ans += candies[i];

        return ans;
    }
};

/* Approach 3 */
/* One pass, O(n) with O(1) space */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size();
        if(l == 1) return 1;
        
        int up = 0, down = 0, peak = 0; 
        /*
        * up : Length of current increasing sequence - 1
        * down: Length of current decreasing sequence - 1
        * peak: Length of last increasing sequence - 1
        */
        int ans = 1;

        for(int i = 1 ; i < l ; i ++){
            if(ratings[i] > ratings[i-1]){ // increasing
                up ++;
                peak = up;
                down = 0;
                ans += (up + 1);
            }
            else if(ratings[i] < ratings[i-1]){ // decreasing
                up = 0;
                down ++;
                ans += (down + int(down > peak)); 
                /* 
                * The head of current decreasing sequence need one more candy if
                * the length of current decreasing seuqence is longer than the length
                * of last increasing sequence.
                */
            }
            else { // same rating
                up = down = peak = 0;
                ans += 1;
                /*
                * The neighbor of same ranking  always need only one candy at the beginning,
                * it might be the head of following increasing or decreasing sequence.
                */
            }
        }

        return ans;
    }
};
