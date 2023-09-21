class Solution {
public:
    bool can[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> exist;
        for(int i = 0 ; i < wordDict.size() ; i ++){
            exist[wordDict[i]] = true;
        }

        can[0] = true;
        int l = s.length();
        for(int i = 0 ; i < l ; i ++){
            for(int j = 0 ; j <= i ; j ++){
                if(can[i-j] && exist.find(s.substr(i-j, j+1)) != exist.end()){
                    can[i+1] = true;
                    break;
                }
            }
        } 
        return can[l];
    }
};
