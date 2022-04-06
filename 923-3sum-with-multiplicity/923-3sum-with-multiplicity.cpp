class Solution {
public:
    int threeSumMulti(vector<int>& nums, int tar) {
        int n=nums.size();
        int count=0;
        int mod=1000000007;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
        {
            int target=tar-nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                if(nums[j]+nums[k]<target) j++;
                else if(nums[j]+nums[k]>target) k--;
                else if(nums[j]!=nums[k])
                {
                    int count1=1;
                    int count2=1;
                    while(j+1<k && nums[j]==nums[j+1])
                    {
                        count1++;
                        j++;
                    }
                    while(k-1>j && nums[k]==nums[k-1])
                    {
                        count2++;
                        k--;
                    }
                    count+=count1*count2;
                    count%=mod;
                    j++;
                    k--;
                }
                else
                {
                    count+=(k-j+1)*(k-j)/2;
                    count%=mod;
                    break;
                }
            }
        }
        return count;
        

    }
};