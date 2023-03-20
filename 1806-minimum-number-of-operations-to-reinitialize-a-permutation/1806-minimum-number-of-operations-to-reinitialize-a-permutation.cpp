class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> curr(n),prev;
        vector<int> org;
        for(int i=0;i<n;i++)
        {
            prev.push_back(i);
            org.push_back(i);
        }
        int count=0;
        while(1)
        {
            for(int i=0;i<n;i++)
            {
                if(i%2)
                {
                    curr[i]=prev[n/2+(i-1)/2];
                    
                }
                else
                {
                    curr[i]=prev[i/2];
                }
            }
            count++;
            if(curr==org) break;
            prev=curr;
        }
        return count;
    }
};