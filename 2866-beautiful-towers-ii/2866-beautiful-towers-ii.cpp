#define ll long long 
class Solution {
public:
    vector<ll> func(vector<int>& H)
    {
        int n = H.size();
        stack<ll> s;
        s.push(0);
        vector<ll> ans(n,0);
        ans[0] = H[0];
        ll sm = 0;
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && H[s.top()]>H[i])
                s.pop();
            if(s.empty())
            {
                ans[i] = (i+1)*1LL*H[i];
                s.push(i);
                continue;
            }
            ans[i] = ans[s.top()] + (i-s.top())*H[i]*1LL;
            s.push(i);
        }
        return ans;
    }     
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<ll> pre,suf;
        pre = func(maxHeights);
        reverse(maxHeights.begin(),maxHeights.end());
        suf = func(maxHeights);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,pre[i]+suf[n-1-i]-maxHeights[n-1-i]*1LL);
        }
        return ans;
    }
};