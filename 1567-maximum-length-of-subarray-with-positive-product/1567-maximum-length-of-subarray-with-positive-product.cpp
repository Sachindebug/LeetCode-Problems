class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        vector<int> temp;
        int res=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                res=max(res,myfun(temp));
                temp.clear();
            }
            else
            {
                temp.push_back(nums[i]);
            }
        }
        res=max(res,myfun(temp));
        return res;
        
    }
    int myfun(vector<int> &arr)
    {
        int n=arr.size();
        if(n==0) return 0;
        int neg=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                neg++;
            }
        }
        if(neg%2==0)
        {
            return n;
        }
        int startidx=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                startidx=i;
                break;
                
            }
        }
        int endidx=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<0)
            {
                endidx=i;
                break;
            }
        }
        return max(n-startidx-1,endidx);
    }
    
};