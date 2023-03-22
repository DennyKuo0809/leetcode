class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long int tmp = 0, mul = 1, len =0, k_ = (long long int)k;
        vector<long long int> lens;
        vector<long long int> nums; 
        vector<long long int> str_begins;
        string ret = "";
        
        bool ini_alphabet = false, ini_digit = false;

        str_begins.push_back(0);
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] - 'a' < 26 && s[i] - 'a' >= 0){
                if(ini_alphabet){
                    str_begins.push_back(i);
                    tmp *= mul;
                    mul = 1;
                }
                len ++;
                tmp ++;
                ini_digit = true;
                ini_alphabet = false;
            }
            else {
                if(ini_digit){
                    lens.push_back(len);
                    nums.push_back(tmp);
                }
                len = 0;
                mul *= (s[i] - '0');
                ini_alphabet = true;
                ini_digit = false;
            }
        }

        if(!nums.size() || k <= lens[0]){
            return ret + s[k-1];
        }

        int index = nums.size() - 1;
        int target_str_index = -1, target_index = -1;

        while(index >= 0 && k_ / nums[index] >= 0){
            k_ = (k_ % nums[index])? (k_ % nums[index]):nums[index];
            if (k_ + lens[index] > nums[index]){
                target_str_index = index;
                target_index = k_ + lens[index] - nums[index] - 1;
                break;
            }
            index --;
        }
        
        if(index < 0){
            target_str_index = 0;
            target_index = (int)k_;
        }
        
        return ret + s[str_begins[target_str_index]+target_index];

    }
};
