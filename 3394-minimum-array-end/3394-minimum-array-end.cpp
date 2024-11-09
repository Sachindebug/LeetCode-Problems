class Solution {
public:
    long long minEnd(int n, int x) {
        long long start = x;
        int count = 0;
        while(count<n-1)
        {
            count++;
            start = (start+1) | x;
        }
        return start;
    }
};