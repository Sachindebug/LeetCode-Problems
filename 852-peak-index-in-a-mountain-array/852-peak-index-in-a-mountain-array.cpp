class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size();
        int m;
        while(l<r)
        {
            m=l+(r-l)/2;
            if(m!=0 && m!=arr.size() && arr[m]>arr[m-1] && arr[m]>arr[m+1])
            {
                return m;
            }
            else if(m!=0 && m!=arr.size() && arr[m]>arr[m-1] && arr[m]<arr[m+1])
            {
                l=m+1;
            }
            else
            {
                r=m;
            }
        }
        return -1;
        
    }
};