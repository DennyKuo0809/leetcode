class Solution {
public:
    unordered_map<int, vector<int> > hasStop;
    bool visited[1000000];

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        queue<int> q;
        for(int i = 0 ; i < routes.size() ; i ++){
            for(int n: routes[i]){
                if(n == source){
                    q.push(i);
                    visited[i] = true;
                }
                hasStop[n].push_back(i);
            }
        }
        q.push(-1);
        int d = 1;
        while(!q.empty()){
            int f = q.front();
            if(f == -1){
                q.pop();
                d ++;
                if(!q.empty()) q.push(-1);
                else break;
            }
            else {
                for(int n: routes[f]){
                    if(n == target) return d;
                    for(int r: hasStop[n]){
                        if(!visited[r]){
                            visited[r] = true;
                            q.push(r);
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }

};
