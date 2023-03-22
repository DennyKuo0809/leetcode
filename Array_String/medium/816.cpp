class Solution {
public:
    vector<string> get(string s){
        vector<string> ret;

        int l = s.length();
        if(l == 1) {
            ret.push_back(s);
        }
        else if(s[0] == '0'){
            if(s[0] == s[l-1]) return ret;
            ret.push_back(s.substr(0, 1) + "." + s.substr(1));
        }
        else if(s[l-1] == '0'){
            ret.push_back(s);
        }
        else{
            ret.push_back(s);
            for(int i = 1 ; i < l ; i ++){
                ret.push_back(s.substr(0, i) + "." + s.substr(i));
            }
        }
        return ret;
    }

    vector<string> ambiguousCoordinates(string s) {
        vector<string> ret;

        int len = s.length();

        string first = "", second = "";

        for(int i = 2 ; i < len - 1 ; i ++){ /* s[1:i], s[i:-2] */
            first += s[i-1];
            second = s.substr(i, len - i - 1);

            vector<string> tmp1 = get(first);
            if(!tmp1.size()) continue;
            vector<string> tmp2 = get(second);
            if(!tmp2.size()) continue;

            for(int j1 = 0 ; j1 < tmp1.size() ; j1 ++){
                for(int j2 = 0 ; j2 < tmp2.size() ; j2 ++){
                    ret.push_back("(" + tmp1[j1] + ", " + tmp2[j2] + ")");
                }
            }
        }

        return ret;
    }
};
