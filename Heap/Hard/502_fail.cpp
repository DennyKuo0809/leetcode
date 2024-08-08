/* The capital is continually increasing, and the previously selected projects remain executable. */
class Solution {
public:
    struct project{
        int profits;
        int capital;
        project(int p, int c): profits(p), capital(c) {}
    };
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<struct project> P;
        for(int i = 0 ; i < profits.size() ; i ++) P.push_back(project(profits[i], capital[i]));
        sort(
            P.begin(), 
            P.end(),
            [&](struct project& a, struct project& b){ return a.capital < b.capital; }
        );

        int cnt = 0;
        int currentC = w;
        priority_queue<int> maxProfit;
        int index = 0;
        while(cnt < k){
            while(index < P.size()){
                if(P[index].capital > currentC) break;
                maxProfit.push(P[index].profits);
                index ++;
            }
            if(maxProfit.empty()) return currentC;
            currentC += maxProfit.top();
            maxProfit.pop();
            cnt ++;
        }
        return currentC;
    }
};
