class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s(banned.begin(),banned.end());
        int count=0;
        long long int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                sum+=i;
                if(sum<=maxSum) count++;
                else break;
            }
            
        }
        return count;
        
    }
};