class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool inc= nums[0]<nums[n-1]? 1 : 0;
        for(int i=0; i<n-1; i++){
          cout<<inc<<endl;
          cout<<i<<nums[i]<<nums[i+1];
          if(inc==1 && nums[i]>nums[i+1])
            return 0;
          
          if(inc==0 && nums[i]<nums[i+1]){
            return 0;
          }
        }
        return 1;
    }
};