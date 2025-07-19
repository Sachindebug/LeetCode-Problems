class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        ans = 0
        vis = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(0,n):
            for j in range(0,m):
                if vis[i][j] == 0 and grid[i][j]!=0:
                    res = self.dfs(grid,vis,i,j)
                    if res%k==0:
                        ans+=1
        return ans

    def dfs(self,grid: List[List[int]],vis: List[List[int]], i: int, j: int):
        n = len(grid)
        m = len(grid[0])
        if i<0 or i>=n or j<0 or j>=m or grid[i][j]==0 or vis[i][j]!=0:
            return 0
        vis[i][j] = 1
        return grid[i][j] + self.dfs(grid,vis,i,j+1) + self.dfs(grid,vis,i,j-1) + self.dfs(grid,vis,i+1,j) + self.dfs(grid,vis,i-1,j)
