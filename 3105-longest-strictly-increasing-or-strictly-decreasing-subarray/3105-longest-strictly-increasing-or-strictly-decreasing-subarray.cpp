class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(isIncreasing(nums,i,j) || isDecreasing(nums,i,j))
                {
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
    bool isIncreasing(vector<int> &arr, int s, int e)
    {
        for(int i=s;i<e;i++)
        {
            if(arr[i]>=arr[i+1]) return false;
        }
        return true;
    }
    bool isDecreasing(vector<int> &arr, int s, int e)
    {
        for(int i=s;i<e;i++)
        {
            if(arr[i]<=arr[i+1]) return false;
        }
        return true;
    }
};