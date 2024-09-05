class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        char start = word[0];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]==start){
                   if(dfs(board,0,i,j,word)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int idx, int i, int j, string &word){
        int n = board.size();
        int m = board[0].size();
        if(idx>=word.length()-1) return true;
        bool res = false;
        if(i<n-1 && board[i+1][j]==word[idx+1]){
            char prev = board[i][j];
            board[i][j]='.';
            res = res | dfs(board,idx+1,i+1,j,word);
            board[i][j] = prev;
        }
        if(j<m-1 && board[i][j+1]==word[idx+1]){
            char prev = board[i][j];
            board[i][j]='.';
            res = res | dfs(board,idx+1,i,j+1,word);
            board[i][j] = prev;
        }
        if(i>0 && board[i-1][j]==word[idx+1]){
            char prev = board[i][j];
            board[i][j]='.';
            res = res | dfs(board,idx+1,i-1,j,word);
            board[i][j] = prev;
        }
        if(j>0 && board[i][j-1]==word[idx+1]){
            char prev = board[i][j];
            board[i][j]='.';
            res = res | dfs(board,idx+1,i,j-1,word);
            board[i][j] = prev;
        }
        return res;
    }
};