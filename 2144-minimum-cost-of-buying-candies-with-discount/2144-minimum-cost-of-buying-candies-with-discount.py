class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort()
        n,ans = len(cost),0
        for i in range (n-3,-1,-3):
            ans+=(cost[i+1]+cost[i+2])
        rem = n%3
        for i in range(0,rem):
            ans+=cost[i]
        return ans
