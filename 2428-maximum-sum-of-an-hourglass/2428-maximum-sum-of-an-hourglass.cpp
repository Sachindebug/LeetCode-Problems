class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
          int maxSum = 0;
          for (int i = 0; i < grid.size() - 2; i++) //row wise traversing 
          {
              for (int j = 0; j < grid[0].size() - 2; j++) //column wise traversing
              {
                  //made it in shape of hourglass for easier to understand! 
                  int currSum = grid[i][j] + grid[i][j+1] + grid[i][j+2] +
                                             grid[i+1][j+1]+
                              grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                  maxSum = max(maxSum, currSum);
              }
          }
          return maxSum;
    }
};