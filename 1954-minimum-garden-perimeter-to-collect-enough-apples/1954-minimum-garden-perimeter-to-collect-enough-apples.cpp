class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long x = 0;
        long long we_have = 0;
 
        while(we_have < neededApples) {
            x++;
            long long s = (3LL * x * (x+1)) / 2LL  +  (3LL * x * (x - 1)) / 2LL;
            we_have += 4 * s;
        }
        
        return 8 * x;
    }
};