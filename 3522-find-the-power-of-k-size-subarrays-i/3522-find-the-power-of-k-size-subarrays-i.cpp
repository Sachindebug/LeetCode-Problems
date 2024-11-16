class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if(k==1){
            for(int i = 0;i<n;i++) res.push_back(nums[i]);
            return res;
        }
        int i = 0;
        int j = 1;
        while(j<n && i<n-k+1){
            if(nums[j-1]==nums[j]-1){
                if((j-i)+1==k) {
                    res.push_back(nums[j]);
                    i++;
                }
                j++;
            }
            else{
                while(i<j){
                    res.push_back(-1);
                    i++;
                }
                j++;
            }
        }
        vector<int> temp;
        for(int i =0;i<n-k+1;i++){
            temp.push_back(res[i]);
        }
        return temp;
    }
};