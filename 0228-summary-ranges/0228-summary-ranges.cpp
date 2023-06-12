class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        if(n==0) return res;
        int start=nums[0];
        int curr=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==curr+1) curr=nums[i];
            else 
            {
                if(curr==start) res.push_back(to_string(start));
                else
                {
                    string s="";
                    s+=to_string(start);
                    s+="->";
                    s+=to_string(curr);
                    res.push_back(s);
                    
                }
                start=nums[i];
                curr=nums[i];
            }
            
        }
        if(curr==start) res.push_back(to_string(start));
        else
        {
                    string s="";
                    s+=to_string(start);
                    s+="->";
                    s+=to_string(curr);
                    res.push_back(s);
                    
        }
        return res;
    }
};