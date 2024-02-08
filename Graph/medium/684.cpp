class Solution {
public:
    vector<int> adj[1001];
    int color[1001];
    bool used[1001];
    map<int, int> edge2index;
    stack<int> path;

    int dfs(int src){
        color[src] = 1;
        path.push(src);
        for(auto neighbor: adj[src]){
            int m = min(src, neighbor), M = max(src, neighbor);
            int index = edge2index[m * 1001 + M];
            if(used[index]) continue;
            if(!color[neighbor]) {
                used[index] = true;
                int ans = dfs(neighbor);
                if(ans >= 0) return ans;
                used[index] = false;
            }
            else if(color[neighbor] == 1){
                int res = index;
                int last = neighbor;
                while(!path.empty()){
                    int i_ = min(last, path.top()) * 1001 + max(last, path.top());
                    res = max(res, edge2index[i_]);
                    if(path.top() == neighbor) break;
                    last = path.top();
                    path.pop();
                }
                return res;
            }
        }
        path.pop();
        color[src] = 2;
        return -1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = -1;
        for(int i = 0 ; i < edges.size() ; i ++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            edge2index[edges[i][0] * 1001 + edges[i][1]] = i;
            N = max(N, edges[i][1]);
        }
        for(int i = 1  ; i <= N ; i ++){
            int ans = dfs(i);
            if(ans >= 0) return edges[ans];
        }
        return edges[0];
    }
};
