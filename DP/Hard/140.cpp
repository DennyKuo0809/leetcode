class Solution {
public:
    unordered_map<string, bool> e;
    string current[20];

    void dfs(vector<string>& sol, string& s, int src, int index){
        if(src == -1){
            string new_s = current[index-1];
            for(int i = index-2 ; i >= 0 ; i --){
                new_s += " " + current[i];
            }
            sol.push_back(new_s);
            return;
        }
        for(int i = src ; i >= 0 ; i --){
            if(e.find(s.substr(i, src-i+1)) != e.end()){
                current[index] = s.substr(i, src-i+1);
                dfs(sol, s, i-1, index+1);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        /* Initilize */
        vector<string> sol;
        for(int i = 0 ; i < wordDict.size() ; i ++) e[wordDict[i]] = true;
        
        /* Dfs */
        dfs(sol, s, s.length()-1, 0);

        return sol;
    }
};
