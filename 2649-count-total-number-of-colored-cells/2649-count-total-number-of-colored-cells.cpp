class Solution {
public:
    long long coloredCells(int n) {
        long long a=n-1;
        return 2*a*(a+1)+1;
    }
};