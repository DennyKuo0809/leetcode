class Solution {
public:
    int freq[26];
    int n_f[11];

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int smallest = 26;
        memset(n_f, 0, sizeof(int) * 10);

        for(int i = 0 ; i < words.size() ; i ++){
            smallest = 26;
            memset(freq, 0, sizeof(int) * 26);
            for(int j = 0 ; j < words[i].length() ; j ++){
                smallest = min(smallest, words[i][j] - 'a');
                freq[words[i][j] - 'a'] ++;
            }
            for(int j = 0 ; j < freq[smallest] ; j ++) n_f[j] ++;
        }

        vector<int> ret;
        for(int i = 0 ; i < queries.size() ; i ++){
            smallest = 26;
            memset(freq, 0, sizeof(int) * 26);
            for(int j = 0 ; j < queries[i].length() ; j ++){
                smallest = min(smallest, queries[i][j] - 'a');
                freq[queries[i][j] - 'a'] ++;
            }
            ret.push_back(n_f[freq[smallest]]);
        }

        return ret;
    }
};
