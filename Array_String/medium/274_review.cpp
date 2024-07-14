class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = 0;
        int l = citations.size();
        for(int i = l-1 ; i >= 0 ; i --){
            if(citations[i] >= (l-i)) ans = l-i;
            else break;
        }
        return ans;
    }
};
