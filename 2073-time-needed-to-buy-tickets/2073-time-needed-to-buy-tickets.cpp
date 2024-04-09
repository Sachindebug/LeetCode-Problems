class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int res=0;
        for(int i=0;i<arr.size();i++)
        {
            if(i<=k)
            {
                if(arr[i]>=arr[k])
                {
                    res+=arr[k];
                }
                else
                {
                    res+=arr[i];
                }
            }
            else
            {
                int x=arr[k]-1;
                if(arr[i]>=x)
                {
                    res+=x;
                }
                else
                {
                    res+=arr[i];
                }
            }
        }
        return res;
        
    }
};