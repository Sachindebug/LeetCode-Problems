class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxGold = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                maxGold =
                    max(maxGold, dfsBacktrack(grid, rows, cols, row, col));
            }
        }
        return maxGold;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

    int dfsBacktrack(vector<vector<int>>& grid, int rows, int cols, int row,int col) {
        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid[row][col] == 0) {
            return 0;
        }
        int maxGold = 0;
        int originalVal = grid[row][col];
        grid[row][col] = 0;
        for (int direction = 0; direction < 4; direction++) {
            maxGold =
                max(maxGold,
                    dfsBacktrack(grid, rows, cols, DIRECTIONS[direction] + row,
                                 DIRECTIONS[direction + 1] + col));
        }
        grid[row][col] = originalVal;
        return maxGold + originalVal;
    }
};