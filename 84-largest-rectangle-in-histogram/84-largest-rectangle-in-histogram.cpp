class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int res=INT_MIN;
        int n=arr.size();
        bool allsame=true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=arr[0])
            {
                allsame=false;
                break;
            }
        }
        if(allsame)
        {
            return n*arr[0];
        }
        for(int i=0;i<n;i++)
        {
            int x=arr[i];
            int l=i-1;
            int r=i+1;
            int count=1;
            while(l>=0)
            {
                if(arr[l]>=x) count++;
                else
                    break;
                l--;
            }
            while(r<n)
            {
                if(arr[r]>=x) count++;
                else
                    break;
                r++;
            }
            res=max(res,x*count);
        }
        return res;
    }
};