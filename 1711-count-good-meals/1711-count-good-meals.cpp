class Solution {
public:
    int countPairs(vector<int>& arr) {
        vector<int> pow;
        for(int i=0;i<22;i++)
        {
            pow.push_back(1<<i);
        }
        map<int,int> ump;
        int n=arr.size();
        for(int i=0;i<n;i++) ump[arr[i]]++;
        long long int ans1=0;
        long long int ans2=0;
        int mod=1e9+7;
        for(auto x:ump)
        {
            long long int a=x.first;
            long long int b=x.second;
            for(int i=0;i<22;i++)
            {
                if(ump.find(pow[i]-a)!=ump.end())
                {
                    if(pow[i]-a==a)
                    {
                        ans1+=(b*(b-1))/2;
                        ans1%=mod;
                    }
                    else
                    {
                        ans2+=(ump[pow[i]-a]*b);
                        ans2%=mod;
                    }
                }
            }
        }
        long long int ans=(ans1+(ans2/2))%mod;
        return ans;
    }
};