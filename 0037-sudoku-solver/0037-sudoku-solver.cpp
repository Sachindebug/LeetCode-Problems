class Solution {
    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
          for(int i=0;i<board.size();i++){
              //Row Check
              if(board[row][i]==val){
                  return false;
              }
              //Column Check
              if(board[i][col]==val){
                  return false;
              }
              // 3*3 Matrix Check
              if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                  return false;
              }
          }
          return true;
    }

    bool solve(vector<vector<char>>& board){
        int n=board[0].size();

        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                //Empty Cell
                if(board[row][col]=='.'){
                    for(char value='1';value<='9';value++){
                        if(isSafe(row,col,board,value)){
                            board[row][col]=value;
                        

                          //Recursive call
                          bool nextsolutionpossible =solve(board);
                          if(nextsolutionpossible){
                              return true;
                          }
                          else{
                              //Backtrack
                              board[row][col]='.';
                          }
                        }
                    }
                 return false; //Not satisfy value from 1 to 9
                }
            }
        }
        return true;
   }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};