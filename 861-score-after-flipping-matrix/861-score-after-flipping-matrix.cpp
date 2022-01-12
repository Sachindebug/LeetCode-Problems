class Solution {
public:
    int matrixScore(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++)
        {
            bool found=false;
            bool todo=false;
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    found=true;
                }
                if(arr[i][j]==0 && !found)
                {
                    todo=true;
                    break;
                }
            }
            if(todo)
            {
                for(int j=0;j<m;j++)
                {
                    arr[i][j]=arr[i][j]^1;
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            int count0=0;
            int count1=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i][j]==1)
                {
                    count1++;
                    
                }
                else count0++;
            }
            if(count0>count1)
            {
                for(int i=0;i<n;i++)
                {
                    arr[i][j]=arr[i][j]^1;
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            int res=0;
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]) 
                {
                    res+=pow(2,(m-j-1));
                }
                
            }
            ans+=res;
            
        }
        return ans;
        
        
    }
};