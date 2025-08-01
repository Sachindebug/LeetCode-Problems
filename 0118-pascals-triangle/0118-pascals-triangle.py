class Solution:
    def generate(self, n: int) -> List[List[int]]:
        res = [[1]]
        i = 1
        while i<n:
            temp = []
            for j in range (i+1):
                if(j==0 or j==i):
                    temp.append(1)
                else:
                    temp.append(res[i-1][j]+res[i-1][j-1])
            res.append(temp)
            i+=1
        return res