/*
* Topological order
* Using reversed edges and post order traversal (dfs)
*/


class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    int color[2000];

    bool dfs(int src){
        color[src] = -1;
        for(int i = 0 ; i < adj[src].size() ; i ++){
            if(color[adj[src][i]] == 1) continue;
            if(color[adj[src][i]] == -1) return false;
            if(!dfs(adj[src][i])) return false;
        }
        color[src] = 1;
        ans.push_back(src);
        return true;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, bool> inDeg;
        for(int i = 0 ; i < numCourses ; i ++){
            adj.push_back(vector<int>());
        }
        for(int i = 0 ; i < prerequisites.size() ; i ++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]); // Reversed Edges
            inDeg[prerequisites[i][1]] = true;
        }
        bool terminal_exist = false;
        for(int i = 0 ; i < numCourses ; i ++){
            if(inDeg.find(i) == inDeg.end()){
                if(!dfs(i)) return vector<int>();
            }
        }
        for(int i = 0; i < numCourses ; i ++){
            if(!color[i]) {
                if(!dfs(i)) return vector<int>();
            }
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};
