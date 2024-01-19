class Solution {
public:
    vector<vector<int>> adj;
    int color[2000];

    bool cycle_detect(int src) {
        color[src] = -1;
        for(int i = 0 ; i < adj[src].size() ; i ++){
            if(color[adj[src][i]] == -1) return true;
            if(color[adj[src][i]] == 1) continue;
            if(cycle_detect(adj[src][i])) return true;
        }
        color[src] = 1;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0 ; i < numCourses ; i ++){
            adj.push_back(vector<int>());
        }
        for(int i = 0 ; i < prerequisites.size() ; i ++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0 ; i < numCourses ; i ++){
            if(!color[i]){
                if(cycle_detect(i)) return false;
            }
        }

        return true;

        
    }
};
