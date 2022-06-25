class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n);
        return mergeSort(nums,temp,0,n-1);
    }
    int mergeSort(vector<int> &nums,vector<int> &temp,int l, int r)
    {
        int count=0;
        int mid;
        if(r>l)
        {
            mid=(l+r)/2;
            count+=mergeSort(nums,temp,l,mid);
            count+=mergeSort(nums,temp,mid+1,r);
            count+=Merge(nums,temp,l,mid,r);
        }
        return count;
    }
    int Merge(vector<int> &arr,vector<int> &temp,int l,int m,int r)
    {
        int i=l;
        int j=m+1;
        int k=l;
        int count=0;
        int p=m+1;
        for(int a=l;a<=m;a++)
        {
            while(p<=r && arr[a]>(2*(long)arr[p]))
            {
                p++;
            }
            count+=(p-m-1);
        }
        while(i<=m && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
               
                temp[k++]=arr[j++];
            }
        }
        while(i<=m)
        {
            temp[k++]=arr[i++];
        }
        while(j<=r)
        {
            temp[k++]=arr[j++];
        }
        for(int a=l;a<=r;a++)
        {
            arr[a]=temp[a];
        }
        return count;
    }
};