/*
* A single state contains both the position of the box and the position of the player.
* Considering the following test case, the player should push the box from (4, 3) to (3, 3) to pass through the wall at column 3.
* Then he pushes it back to (4, 3), and continues pushing it into the target grid.
* Hence, in an optimal solution, a box might pass through a single grid more than once, 
* but the position of the player should be different each time.
*/

// [
//     [# . . # # # # #],
//     [# . . T # . . #],
//     [# . . . # B . #],
//     [# . . . . . . #],
//     [# . . . # . S #],
//     [# . . # # # # #]
// ]

class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    int R = -1, C = -1;
    bool visited_player[20][20];
    map<pair<int, int>, bool> visited_box;

    bool valid(int r, int c, vector<vector<char>>& grid){
        return (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != '#');
    }

    bool dfs_player(int r, int c, int dest_r, int dest_c, int box_r, int box_c, vector<vector<char>>& grid){
        visited_player[r][c] = true;
        if(r == dest_r && c == dest_c) return true;
        for(int d = 0 ; d < 4 ; d ++){
            int new_r = r + dr[d], new_c = c + dc[d];
            if(!valid(new_r, new_c, grid) || (new_r == box_r && new_c == box_c) || visited_player[new_r][new_c]) continue;
            if(new_r == dest_r && new_c == dest_c) return true;
            if (dfs_player(new_r, new_c, dest_r, dest_c, box_r, box_c, grid)) return true;
        }
        return false;
    }

    int bfs_box2target(int r, int c, int player_r, int player_c, vector<vector<char>>& grid){
        queue<pair<int, int> > q;
        q.push(
            make_pair(r*C+c, player_r*C+player_c)
        );
        int dist = 0;
        while(!q.empty()){
            int N = q.size();
            for(int i = 0 ;  i < N ; i ++){
                auto f = q.front();
                int br = (f.first) / C, bc = (f.first) % C, sr = (f.second) / C, sc = (f.second) % C;
                for(int d = 0 ; d < 4 ; d ++){
                    int nr = br + dr[d], nc = bc + dc[d];
                    int pr = br - dr[d], pc = bc - dc[d];
                    auto state = make_pair(nr*C+nc, pr*C+pc);
                    if(!valid(nr, nc, grid) || !valid(pr, pc, grid) || visited_box[state]) continue;

                    memset(visited_player, 0, sizeof(visited_player));
                    if(!dfs_player(sr, sc, pr, pc, br, bc, grid)) continue;

                    if(grid[nr][nc] == 'T') return dist + 1;
                    q.push(state);
                    visited_box[state] = true;
                }
                q.pop();
            }
            dist ++;
        }
        return -1;
    }


    int minPushBox(vector<vector<char>>& grid) {
        R = grid.size();
        C = grid[0].size();
        int sr = -1, sc = -1;
        int br = -1, bc = -1;
        for(int i = 0 ; i < R ; i ++){
            for(int j = 0 ; j < C ; j ++){
                if(grid[i][j] == 'B'){
                    br = i;
                    bc = j;
                }
                else if(grid[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
            }
        }
        return bfs_box2target(br, bc, sr, sc, grid);
    }
};
