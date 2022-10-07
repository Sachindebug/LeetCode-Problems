class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>> nums;
        for(auto i:arr)
        {
            nums.push_back({abs(i-x),i});
        }
        sort(nums.begin(),nums.end());
        
        vector<int> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(nums[i].second);
        }
        sort(res.begin(),res.end());
        return res;
    }
};