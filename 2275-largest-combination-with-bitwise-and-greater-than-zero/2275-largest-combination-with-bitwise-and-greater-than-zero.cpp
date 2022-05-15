class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int arr[32]={0};
        for(int i=31;i>=0;i--)
        {
            for(int j=0;j<candidates.size();j++)
            {
                if(candidates[j] & (1<<i)) arr[i]++;
            }
        }
        int res=INT_MIN;
        for(int i=0;i<32;i++)
        {
            res=max(res,arr[i]);
        }
        return res;
    }
};