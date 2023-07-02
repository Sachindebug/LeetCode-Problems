class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> temp(k,0);
        return recurse(cookies,k,0,temp);
    }
    int recurse(vector<int> &arr,int k,int idx,vector<int> &temp)
    {
        if(idx==arr.size())
        {
            int res=0;
            for(int i=0;i<k;i++)
            {
                res=max(res,temp[i]);
            }
            return res;
        }
        int ele = arr[idx];
        int ans=INT_MAX;
        for(int j=0;j<k;j++)
        {
            temp[j]+=ele;
            ans=min(ans,recurse(arr,k,idx+1,temp));
            temp[j]-=ele;
        }
        return ans;
    }
};