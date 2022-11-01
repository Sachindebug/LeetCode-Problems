class Solution {
public:
    vector<int> findBall(vector<vector<int>>& arr) {
        int n=arr[0].size();
        vector<int> ans(n,1);
        for(int k=0;k<n;k++)
        {
            int i=0;
            int j=k;
            while(i<arr.size())
            {
                if(arr[i][j]==1)
                {
                    if(j==n-1)
                    {
                        ans[k]=-1;
                        break;
                    }
                    else if(arr[i][j]!=arr[i][j+1])
                    {
                        ans[k]=-1;
                        break;
                    }
                    i++;
                    j++;
                }
                else
                {
                    if(j==0)
                    {
                        ans[k]=-1;
                        break;
                    }
                    else if(arr[i][j]!=arr[i][j-1])
                    {
                        ans[k]=-1;
                        break;
                    }
                    i++;
                    j--;
                    
                }
            }
            if(ans[k]!=-1)
            ans[k]=j;
        }
        return ans;
        
    }
};