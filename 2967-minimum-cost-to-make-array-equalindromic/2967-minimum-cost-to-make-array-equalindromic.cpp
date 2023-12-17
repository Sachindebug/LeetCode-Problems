class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
    
        int median = nums[n/2];
        int med1 = median;
        int med2 = median;
        
        while(!palindrome(med1)) med1--;
        while(!palindrome(med2)) med2++;
        
        long long ans1 = check(nums,med1);
        long long ans2 = check(nums,med2);
        
        return min(ans1,ans2);
        
    }
   long long check(vector<int>& nums,int x){
        long long cost = 0;
        for(auto &i:nums){
            cost += abs(i - x);
        }
        return cost;
    }
    bool palindrome(int num){
        string str = to_string(num);
        int i = 0, j = str.size()-1;
        while(i < j){
            if(str[i++] != str[j--]){
                return false;
            }
        }
        return true;
        
    }
};