class Solution {
public:
    bool ispossible(vector<int> &arr,int d,int b)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>b) return false;
            if(sum+arr[i]>b)
            {
                count++;
                sum=arr[i];
            }
            else
            {
                sum+=arr[i];
            }
        }
        if(count>d) return false;
        else return true;
    }
    int splitArray(vector<int>& arr, int days) {
        int l=*max_element(arr.begin(),arr.end());
        int r=accumulate(arr.begin(),arr.end(),0);
        int m;
        while(l<r)
        {
            m=l+(r-l)/2;
            if(ispossible(arr,days,m))
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
        
    }
};