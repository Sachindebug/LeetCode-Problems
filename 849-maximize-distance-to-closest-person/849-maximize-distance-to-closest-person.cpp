class Solution {
public:
    int maxDistToClosest(vector<int>& arr) {
        int dis=INT_MIN;
        int prev=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                prev=i;
                break;
            }
        }
        dis=(prev);
        for(int i=prev+1;i<n;i++)
        {
            if(arr[i]==1)
            {
                dis=max(dis,(i-prev)/2);
                prev=i;
            }
        }
        dis=max(dis,(n-1-prev));
        return dis;
      
    }
};