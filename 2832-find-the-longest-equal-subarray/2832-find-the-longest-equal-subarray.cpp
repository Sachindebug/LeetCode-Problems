class Solution {
public:
    int cal(vector<int>& nums, int k){
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 1;
        while(j<n){
            while(nums[j]-nums[i]-(j-i)>k){
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        map<int,vector<int>> ump;
        for(int i = 0;i<n;i++){
            ump[nums[i]].push_back(i);
        }
        for(auto x:ump){
            vector<int> pos = x.second;
            ans = max(ans, cal(pos,k));
        }
        return ans;
    }
};