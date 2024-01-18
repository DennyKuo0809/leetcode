class Solution {
public:

    int dis[100][100];
    bool vis[100][100];
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0 ; i < n ; i ++) {
            for(int j = 0 ; j < n ; j ++){
                dis[i][j] = 205;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(grid[i][j]) {
                    dis[i][j] = 0;
                    q.push(i * n + j);
                }
            }
        }

        while(!q.empty()){
            int r_ = q.front() / n, c_ = q.front() % n;
            for(int i = 0 ; i < 4 ; i ++){
                int nr = r_ + dr[i], nc = c_ + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] || vis[nr][nc]) continue;
                if(dis[r_][c_] + 1 < dis[nr][nc]){
                    dis[nr][nc] = dis[r_][c_] + 1;
                    q.push(nr * n + nc);
                }
            }
            q.pop();
        }


        int max_dis = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                max_dis = max(max_dis, dis[i][j]);
            }
        }
        return (max_dis == 205 || max_dis == 0) ? (-1) : max_dis;
        
    }
};
