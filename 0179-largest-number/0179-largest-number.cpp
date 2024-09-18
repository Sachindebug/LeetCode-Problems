class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        for(int i=0;i<n;i++)
        {
            string s1=to_string(nums[i]);
            res.push_back(s1);
            
        }
        sort(res.begin(),res.end(),[](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res1="";
        for(int i=0;i<n;i++)
        {
            res1+=res[i];
            
        }
        int i=0;
        int p=-1;
        while(i<res1.length() && res1[i]=='0')
        {
            p++;
            i++;
            
        }
        if(p==n-1)
        {
            return "0";
        }
        
    
    
        return res1;
        
    }
};