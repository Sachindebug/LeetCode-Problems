class Solution {
public:
   long long maxStrength(vector<int>& nums) {
       if(nums.size()<=1) return nums[0];
       vector<int> neg;
       long long res=1;
       int zero=0,count=0;
       for(auto x:nums)
       {
               if(x==0) zero++;
               if(x!=0) res*=x;
               if(x<0) 
               {
                   neg.push_back(x);
                   count++;
               }
        }
       if(zero==nums.size() || (count==1 && zero==nums.size()-1)) return 0;
       sort(neg.begin(),neg.end(),greater<int>());
       if(res>0) return res;
       return res/neg[0];
       
    }
    
};