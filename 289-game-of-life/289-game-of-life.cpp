class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int count=0;
                if(i>0 && board[i-1][j]) count++;
                if(i<n-1 && board[i+1][j]) count++;
                if(j>0 && board[i][j-1]) count++;
                if(j<m-1 && board[i][j+1]) count++;
                if(i>0 && j>0 && board[i-1][j-1]) count++;
                if(i>0 && j<m-1 && board[i-1][j+1]) count++;
                if(i<n-1 && j<m-1 && board[i+1][j+1]) count++;
                if(i<n-1 && j>0 && board[i+1][j-1]) count++;
                if(board[i][j]==0)
                {
                    if(count==3)
                    {
                        arr[i][j]=1;
                    }
                    else
                    {
                        arr[i][j]=0;
                    }
                }
                if(board[i][j]==1)
                {
                    if(count<2)
                    {
                        arr[i][j]=0;
                    }
                    else if(count>3)
                    {
                        arr[i][j]=0;
                    }
                    else
                    {
                        arr[i][j]=1;
                    }
                }


            }
        }
        board=arr;
        
    }
};