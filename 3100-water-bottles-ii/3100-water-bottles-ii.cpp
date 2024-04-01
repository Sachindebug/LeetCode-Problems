class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        return solve(numBottles, numExchange, 0, 0);
    }
    int solve(int numBottles, int numExchange, int emptyBottles, int sum){
        if(emptyBottles < numExchange && numBottles == 0)
            return sum;
        if(numBottles > 0) return solve(0, numExchange, emptyBottles+numBottles, sum+numBottles);
        else return solve(numBottles+1, numExchange+1, emptyBottles-numExchange, sum);
    }
};