class Solution {
public:
    int t[4];
    bool used[4];
    int arr_[4];
    int max_h = 0, max_m = 0, h, m;
    string max_h_s = "", max_m_s = "";

    void permutation(int d){
        if(d == 4){
            h = t[0] * 10 + t[1];
            m = t[2] * 10 + t[3];
            if(h > 23 || m > 59) return;
            if(h > max_h || (h == max_h && m >= max_m)){
                max_h = h;
                max_m = m;
                max_h_s = "" + to_string(t[0]) + to_string(t[1]);
                max_m_s = "" + to_string(t[2]) + to_string(t[3]);
            }
        }
        else{
            for(int i = 0 ; i < 4 ; i ++){
                if(!used[i]){
                    t[d] = arr_[i];
                    used[i] = true;
                    permutation(d+1);
                    used[i] = false;
                }
            }
        }
    }

    string largestTimeFromDigits(vector<int>& arr) {
        for(int i = 0 ; i < 4 ; i ++){
            used[i] = false;
            arr_[i] = arr[i];
        }
        permutation(0);
        return (max_h_s == "")? (""):(max_h_s + ":" + max_m_s);
    }
};
