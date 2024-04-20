class Solution {
public:
    void dfs(vector<vector<char>>& board,int x, int y)
    {
        board[x][y] = '.';
        int n = board.size();
        int m = board[0].size();
        if(x+1<n && board[x+1][y]=='X') dfs(board,x+1,y);
        if(y+1<m && board[x][y+1]=='X') dfs(board,x,y+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='X')
                {
                    dfs(board,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};