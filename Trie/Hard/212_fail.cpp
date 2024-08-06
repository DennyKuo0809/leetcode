/* Construct a trie for the words to be searched, and cut dfs based on the trie. */
class Solution {
public:
    struct trieNode{
        char c;
        vector<struct trieNode*> next = vector<struct trieNode*>(26, NULL);
        int index = -1;
        trieNode(char x): c(x) {}
    };
    vector<struct trieNode*> Trie = vector<struct trieNode*>(26, NULL);

    int dr[4] = {0, 1, -1, 0};
    int dc[4] = {1, 0, 0, -1};
    bool seen[12][12];

    vector<string> ans;

    void dfs(vector<string>& words, vector<vector<char>>& board, int r, int c, struct trieNode* current){
        if(current -> index >= 0){
            ans.push_back(words[current -> index]);
            current -> index = -1;
        }
        for(int i = 0 ; i < 4 ; i ++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size() || seen[nr][nc]) 
                continue;
            
            seen[nr][nc] = true;
            if(current -> next[board[nr][nc]-'a']) /* Search if the letter were in the Trie */
                dfs(words, board, nr, nc, current -> next[board[nr][nc]-'a']);
            seen[nr][nc] = false;
            
        }
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /* Construct the Trie */
        for(int index = 0 ; index < words.size() ; index ++){
            string word = words[index];
            if(Trie[word[0]-'a'] == NULL) Trie[word[0]-'a'] = new struct trieNode(word[0]);
            struct trieNode* current = Trie[word[0]-'a'];
            for(int i = 1 ; i < word.length() ; i ++){
                if(current -> next[word[i]-'a'] == NULL)
                    current -> next[word[i]-'a'] = new struct trieNode (word[i]);
                current = current -> next[word[i]-'a'];
            }
            current -> index = index; /* The end of index-th word */
        }

        /* DFS */
        for(int r = 0 ; r < board.size() ; r ++){
            for(int c = 0 ; c < board[0].size() ; c ++){
                if(Trie[board[r][c]-'a']) {
                    memset(seen, 0, sizeof(seen));
                    seen[r][c] = true;
                    dfs(words, board, r, c, Trie[board[r][c]-'a']);
                }
            }
        }
        
        return ans;
    }
};
