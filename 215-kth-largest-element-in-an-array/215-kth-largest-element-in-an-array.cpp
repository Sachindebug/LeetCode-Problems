class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,k);
        
    }
    int quickSelect(vector<int> &arr,int l,int r, int k)
    {
        if(k>0 && k<=r-l+1)
        {
            int idx=partition(arr,l,r);
            if(idx-l==k-1) return arr[idx];
            else if(idx-l>k-1) return quickSelect(arr,l,idx-1,k);
            else return quickSelect(arr,idx+1,r,k-idx+l-1);
            
        }
        return INT_MAX;
        
    }
    int partition(vector<int> &arr,int l ,int r)
    {
        int x=arr[r];
        int i=l;
        for(int j=l;j<r;j++)
        {
            if(arr[j]>=x)
            {
                swap(arr[j],arr[i]);
                i++;
            }
        }
        swap(arr[i],arr[r]);
        return i;
    }
};