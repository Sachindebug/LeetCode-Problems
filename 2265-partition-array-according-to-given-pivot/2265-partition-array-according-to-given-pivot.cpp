class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        for(auto x:nums)
        {
            if(x<pivot)
            res.push_back(x);
        }
        for(auto x:nums)
        {
            if(x==pivot)
            res.push_back(x);
        }
        for(auto x:nums)
        {
            if(x>pivot)
            res.push_back(x);
        }
        return res;
    }
};