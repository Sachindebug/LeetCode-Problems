class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int result = 0;
        unordered_map<int, int>map; 
        while(i<nums.size()){
            map[nums[i]]++;
            while(map[nums[i]]>k){
                map[nums[j]]--;
                j++;
            }
            result = max(result, i-j+1);
            i++;
        }
        return result;
    }
};