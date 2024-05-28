class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int> ump;
        for(auto x:nums1)
        {
            if(x%k) continue;
            else
            {
                int p = x/k;
                for(int i = 1;i*i<=p;i++)
                {
                    if(p%i==0)
                    {
                       if(i*i==p) ump[i]++;
                        else
                        {
                            ump[i]++;
                            ump[p/i]++;
                        } 
                    }
                }
            }
        }
        long long res = 0;
        for(auto x:nums2) res+=1ll*ump[x];
        return res;
    }
};