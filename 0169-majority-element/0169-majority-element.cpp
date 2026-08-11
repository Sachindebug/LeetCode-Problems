class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 1;
        int majorityElement = nums[0];
        for(int i = 1; i <= nums.size()-1 ; i++ ){
            if(nums[i] == majorityElement){
                x++;
            }
            else {
                x--;
            }
            if (x == 0){
                majorityElement = nums[i];
                x = 1;
            }
        }
    return majorityElement;
    }
};