class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res=-10001;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        res=double(sum)/double(k);
        int start=0;
        for(int i=k;i<n;i++)
        {
            sum+=nums[i];
            sum-=nums[start];
            start++;
            res=max(res,double(sum)/double(k));
        }
        return res;
        
    }
};