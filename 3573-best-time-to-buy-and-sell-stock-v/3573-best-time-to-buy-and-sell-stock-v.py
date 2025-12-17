class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        def solve(ind, k, state, prices, dp):
            if ind>=n:
                if state==0:
                    return 0
                else:
                    return float('-inf')
            
            if dp[ind][k][state]!=-1:
                return dp[ind][k][state]
            
            nottake=solve(ind+1, k, state, prices, dp)

            take=float('-inf')
            
            if k>0:
                if state==1:
                    #Selling => normal transaction
                    take=prices[ind]+solve(ind+1, k-1, 0, prices, dp)
                elif state==2:
                    #Buy back => short selling transaction
                    take=-prices[ind]+solve(ind+1, k-1, 0, prices, dp)
                else:
                    #Fresh start
                    take=max(
                        -prices[ind]+solve(ind+1, k, 1, prices, dp),  #buy (normal)
                        prices[ind]+solve(ind+1, k, 2, prices, dp)  #short sell
                    )
            
            dp[ind][k][state]=max(take, nottake)

            return dp[ind][k][state]
        
        n=len(prices)

        dp=[[[-1 for _ in range(3)]for _ in range(k+1)]for ind in range(n)]

        return solve(0, k, 0, prices, dp)