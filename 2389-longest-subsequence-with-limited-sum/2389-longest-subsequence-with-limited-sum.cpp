class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i=0;i<q.size();i++)
        {
            int x=q[i];
            long long int sum=0;
            int idx=0;
            for(int j=0;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum>x)
                {
                    idx=j;
                    break;
                }
            }
            if(nums[0]<=x && idx==0) idx=nums.size();
            res.push_back(idx);
        }
        return res;
    }
};