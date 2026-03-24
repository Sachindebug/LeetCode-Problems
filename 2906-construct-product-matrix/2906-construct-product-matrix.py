class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        pref_prod = []
        suff_prod = []
        n,m = len(grid),len(grid[0])
        curr = 1
        for i in range(0,n):
            for j in range(0,m):
                curr*=grid[i][j]
                curr%=12345
                pref_prod.append(curr)
        curr=1
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                curr*=grid[i][j]
                curr%=12345
                suff_prod.append(curr)
        
        suff_prod.reverse()

        res=[[1 for i in range(0,m)] for j in range(0,n)]

        for i in range(0,n):
            for j in range(0,m):
                idx = (i*m)+j
                prev = pref_prod[idx-1] if idx>0 else 1
                nxt = suff_prod[idx+1] if idx<(m*n-1) else 1
                res[i][j] = (prev*nxt)%12345
        
        return res
