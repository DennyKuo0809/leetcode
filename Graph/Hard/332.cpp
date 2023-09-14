/* Solution 1:
 * 此題目相當於給定 Euler Path 的起點，並保證圖中具有 Euler Path ，並尋找 Euler Path。
 * 因此採用 DFS ，在 DFS 到底並且發現沒有辦法走過所有邊之後，直接回溯並丟棄被回溯的邊，直到找到可以經過所有邊的路徑。
*/
class Solution {
public:
    map<string, vector<int>> adj;
    int path[300];
    bool used[300];
    bool found = false;

    void dfs_euler(string current, int d, vector<vector<string>>& tickets){
        for(int i = 0 ; i < adj[current].size() ; i ++){
            if(found) break;
            if(!used[adj[current][i]]){
                used[adj[current][i]] = true;
                path[d] = adj[current][i];
                dfs_euler(tickets[adj[current][i]][1], d+1, tickets);
                used[adj[current][i]] = false;
            }
        }
        if(d == tickets.size()-1) found = true;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /* Make Adjency List */
        for(int i = 0;  i < tickets.size() ; i ++){
            if(adj.find(tickets[i][0]) == adj.end()){
                adj[tickets[i][0]] = vector<int>();
                adj[tickets[i][0]].push_back(i);
            }
            else{
                adj[tickets[i][0]].insert(
                    lower_bound(
                        adj[tickets[i][0]].begin(), 
                        adj[tickets[i][0]].end(), 
                        i,
                        [&](const int& a, const int& b){
                            return tickets[a][1] < tickets[b][1];
                        }
                    ), i
                );

            }
        }

        /* DFS to find Euler Path */
        memset(used, 0, sizeof(used));
        dfs_euler("JFK", 0, tickets);

        /* Reconstruct the path */
        vector<string> res;
        res.push_back("JFK");
        for(int i = 0 ; i < tickets.size() ; i ++){
            res.push_back(tickets[path[i]][1]);
        }

        return res;
    }
};


/* Solution 2:
 * 直接刪除走過的邊，因為
 * 1. 每次 DFS ，會把路徑上除了起終點以外的每個 nodes 的 indegree 和 outdegree 都 -1。 
 *       因此第一次 DFS 的終點一定是 Euler Path 的終點，因為其 outdegree = indegree -1。
 * 2. 直接把 DFS Path 從圖上拿掉的話，會讓剩下的圖的所有點的 indegree = outdegree，因此剩下的圖絕對包含 Euler Cycle。
 * 3. 因此，我們可以每次 DFS 就刪除路徑。在 DFS 到底時回溯，從其中一點繼續 DFS ，必定能找到 Euler Cycle 回到該點。
 * 4. 也因此，要在走過所有鄰居之後才能將此點記錄在路徑中。並在最後 reverse。 
*/
class Solution {
public:
    map<string, vector<string>> adj;
    vector<string> res;

    void dfs_euler(string current){
        while(adj[current].size()){
            string next = adj[current][0];
            adj[current].erase(adj[current].begin());
            dfs_euler(next);
        }
        res.push_back(current);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /* Make Adjency List */
        for(int i = 0;  i < tickets.size() ; i ++){
            if(adj.find(tickets[i][0]) == adj.end()){
                adj[tickets[i][0]] = vector<string>();
                adj[tickets[i][0]].push_back(tickets[i][1]);
            }
            else{
                adj[tickets[i][0]].insert(
                    lower_bound(
                        adj[tickets[i][0]].begin(), 
                        adj[tickets[i][0]].end(), 
                        tickets[i][1]
                    ), tickets[i][1]
                );

            }
        }

        /* DFS to find Euler Path */
        dfs_euler("JFK");

        /* Reconstruct the path */
        reverse(res.begin(), res.end());

        return res;
    }
};
