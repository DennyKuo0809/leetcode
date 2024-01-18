class Solution {
public:
    bool visited[10000];
    int ans[10000];

    bool dfs(vector<vector<int>>& graph, int src){
        if(ans[src] >= 0) return ans[src];
        visited[src] = true;
        for(int i = 0 ; i < graph[src].size() ; i ++){
            if(visited[graph[src][i]]) return ans[graph[src][i]] = 0;
            visited[graph[src][i]] = true;
            if(!dfs(graph, graph[src][i])) return ans[graph[src][i]] = 0;
            visited[graph[src][i]] = false;
        }
        visited[src] = false;
        return ans[src] = 1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        for(int i = 0 ; i < n ; i ++) ans[i] = -1;
        for(int i = 0 ; i < n ; i ++){
            if(dfs(graph, i)) res.push_back(i);
        }
        return res;
    }
};
