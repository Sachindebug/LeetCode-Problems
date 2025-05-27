class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long sum = (n*(n+1))/2;
        long long div = (n/m);
        long long sumDiv = 1ll*((div*(div+1))/2)*m;
        return sum - (2*sumDiv);
    }
};